#!/bin/sh
#
# javawrapper.sh
#
# Allow the installation of several Java Virtual Machines on the system.
# They can then be selected from based on environment variables and the
# configuration file.
#
# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42, (c) Poul-Henning Kamp):
# Maxim Sobolev <sobomax@FreeBSD.org> wrote this file.  As long as you retain
# this notice you can do whatever you want with this stuff. If we meet some
# day, and you think this stuff is worth it, you can buy me a beer in return.
#
# Maxim Sobolev
# ----------------------------------------------------------------------------
#
# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42, (c) Poul-Henning Kamp):
# Greg Lewis <glewis@FreeBSD.org> substantially rewrote this file.  As long
# as you retain this notice you can do whatever you want with this stuff. If
# we meet some day, and you think this stuff is worth it, you can buy me a
# beer in return.
#
# Greg Lewis
# ----------------------------------------------------------------------------
#
# $FreeBSD$
#
# MAINTAINER=java@FreeBSD.org

SAVE_PATH=${PATH}
export PATH=/bin:/sbin:/usr/bin:/usr/sbin

PREFIX="%%PREFIX%%"
CONF="${PREFIX}/etc/javavms"
IAM=`basename "${0}"`
MAKE=/usr/bin/make

#
# Try to run a Java command.
#
tryJavaCommand () {
    # Check for the command being executable and exec it if so.
    if [ -x "${1}" ]; then
        if [ ! -z "${SAVE_PATH}" ]; then
            export PATH=${SAVE_PATH}
        fi
        exec "${@}"
    fi

    echo "${IAM}: warning: couldn't run specified Java command - \"${1}\"" >&2
}

#
# Create symbolic links for all of a Java VMs executables.
#
createJavaLinks () {
    for exe in "${1}"/bin/* "${1}"/jre/bin/*; do
        if [ -x "${exe}" -a \
             ! -d "${exe}" -a \
             "`basename "${exe}"`" = "`basename "${exe}" .so`" -a \
             ! -e "${PREFIX}/bin/`basename "${exe}"`" -a \
             -w "${PREFIX}/bin" ]; then
            ln -s "${PREFIX}/bin/javavm" \
                "${PREFIX}/bin/`basename "${exe}"`" 2>/dev/null
        fi
    done
}

#
# Sort the configuration file
#
sortConfiguration () {
    # Ensure the configuration file exists
    if [ ! -f "${CONF}" ]; then
        return
    fi

    # Ensure the configuration file has the correct permissions
    if [ ! -w "${CONF}" -o ! -r "${CONF}" ]; then
        echo "${IAM}: error: can't read/write ${CONF} configuration file!" >&2
        return
    fi

    ifs="${IFS}"
    IFS=:
    cat "${CONF}" | \
    (
    export JAVAVMS
    while read JAVAVM; do
        VM=`echo "${JAVAVM}" | sed -E 's|[[:space:]]*#.*||' 2>/dev/null`
        # Check that the VM exists and is "sane"
        if [ ! -e "${VM}" ]; then
            continue
        fi
        if [ -d "${VM}" ]; then
            continue
        fi
        if [ ! -x "${VM}" ]; then
            continue
        fi
        if [ `basename "${VM}"` != "java" ]; then
            continue
        fi
        if [ "`realpath "${VM}" 2>/dev/null `" = "${PREFIX}/bin/javavm" ]; then
            continue
        fi
        # Skip duplicate VMs
        if [ ! -z "${JAVAVMS}" ]; then
            for _JAVAVM in ${JAVAVMS}; do
                if [ -z "${_JAVAVM}" ]; then
                    continue
                fi
                _VM=`echo "${_JAVAVM}" | sed -E 's|[[:space:]]*#.*||' 2>/dev/null`
                if [ "x${VM}" = "x${_VM}" ]; then
                    continue 2
                fi
            done
        fi
        VM=`dirname "${VM}"`
        VM=`dirname "${VM}"`
        VM=`basename "${VM}"`
        _JAVAVMS=:
        for _JAVAVM in ${JAVAVMS}; do
            if [ -z "${_JAVAVM}" ]; then
                continue
            fi
            if [ -z "${JAVAVM}" ]; then
                _JAVAVMS="${_JAVAVMS}:${_JAVAVM}"
                continue
            fi
            _VM=`echo "${_JAVAVM}" | sed -E 's|[[:space:]]*#.*||' 2>/dev/null`
            _VM=`dirname "${_VM}"`
            _VM=`dirname "${_VM}"`
            _VM=`basename "${_VM}"`
            VERSION=`echo ${VM} | sed -e 's|[^0-9]*||' 2>/dev/null`
            _VERSION=`echo ${_VM} | sed -e 's|[^0-9]*||' 2>/dev/null`
            if [ "${VERSION}" \> "${_VERSION}" ]; then
                _JAVAVMS="${_JAVAVMS}:${JAVAVM}:${_JAVAVM}"
                JAVAVM=
                continue
            elif [ "${VERSION}" \< "${_VERSION}" ]; then
                _JAVAVMS="${_JAVAVMS}:${_JAVAVM}"
                continue
            else
                case "${VM}" in
                    diablo-jdk*)
                        _JAVAVMS="${_JAVAVMS}:${JAVAVM}:${_JAVAVM}"
                        JAVAVM=
                        continue
                        ;;
                    diablo-jre*|jdk*)
                        case "${_VM}" in
                            diablo*)
                                _JAVAVMS="${_JAVAVMS}:${_JAVAVM}"
                                continue
                                ;;
                            *)
                                _JAVAVMS="${_JAVAVMS}:${JAVAVM}:${_JAVAVM}"
                                JAVAVM=
                                continue
                                ;;
                        esac
                        ;;
                    jre*|linux-sun-jdk*)
                        case "${_VM}" in
                            diablo*|j*)
                                _JAVAVMS="${_JAVAVMS}:${_JAVAVM}"
                                continue
                                ;;
                            *)
                                _JAVAVMS="${_JAVAVMS}:${JAVAVM}:${_JAVAVM}"
                                JAVAVM=
                                continue
                                ;;
                        esac
                        ;;
                    linux-sun-jre*|linux-blackdown-jdk*)
                        case "${_VM}" in
                            diablo*|j*|linux-sun*)
                                _JAVAVMS="${_JAVAVMS}:${_JAVAVM}"
                                continue
                                ;;
                            *)
                                _JAVAVMS="${_JAVAVMS}:${JAVAVM}:${_JAVAVM}"
                                JAVAVM=
                                continue
                                ;;
                        esac
                        ;;
                    linux-blackdown-jre*|linux-ibm-jdk*)
                        case "${_VM}" in
                            diablo*|j*|linux-sun*|linux-blackdown*)
                                _JAVAVMS="${_JAVAVMS}:${_JAVAVM}"
                                continue
                                ;;
                            *)
                                _JAVAVMS="${_JAVAVMS}:${JAVAVM}:${_JAVAVM}"
                                JAVAVM=
                                continue
                                ;;
                        esac
                        ;;
                esac
                _JAVAVMS="${_JAVAVMS}:${_JAVAVM}"
            fi
        done
        JAVAVMS="${_JAVAVMS}"
        if [ ! -z "${JAVAVM}" ]; then
            JAVAVMS="${JAVAVMS}:${JAVAVM}"
        fi
    done;
    if [ ! -z "${JAVAVMS}" ]; then
        rm "${CONF}"
        for JAVAVM in ${JAVAVMS}; do
            if [ ! -z "${JAVAVM}" ]; then
                echo "${JAVAVM}" >> "${CONF}"
            fi
        done
    fi
    )

    IFS="${ifs}"
}

#
# Check all of the VMs in the configuration file
#
checkVMs () {
    # Ensure the configuration file exists
    if [ ! -f "${CONF}" ]; then
        exit 0
    fi

    # Ensure the configuration file has the correct permissions
    if [ ! -w "${CONF}" -o ! -r "${CONF}" ]; then
        echo "${IAM}: error: can't read/write ${CONF} configuration file!" 1>&2
        exit 1
    fi

    # Sort the configuration.  This will also remove duplicates and
    # non-existent VMs
    sortConfiguration

    # Ensure links are created for every executable for a VM.
    cat "${CONF}" | \
    (
    while read JAVAVM; do
        VM=`echo "${JAVAVM}" | sed -E 's|[[:space:]]*#.*||' 2>/dev/null`
        # Create symbolic links as appropriate if they don't exist.
        JAVA_HOME=`dirname "${VM}"`
        JAVA_HOME=`dirname "${JAVA_HOME}"`
        createJavaLinks "${JAVA_HOME}"
    done;
    )

    exit 0
}

#
# Register a new Java VM.
#
registerVM () {
    # Check the java command given to us.
    if [ -z "${1}" ]; then
       echo "Usage: ${IAM} path"
       exit 1
    fi

    # Create the configuration file if it doesn't exist
    if [ ! -e "${CONF}" ]; then
       touch "${CONF}"
    fi

    # Ensure the configuration file exists and has the correct permissions
    if [ ! -f "${CONF}" -o ! -w "${CONF}" -o ! -r "${CONF}" ]; then
        echo "${IAM}: error: can't read/write ${CONF} configuration file!" 1>&2
        exit 1
    fi

    # Check that the given VM can be found in the configuration file
    VM=`echo "${1}" | sed -E 's|[[:space:]]*#.*||' 2>/dev/null`
    REGISTERED=
    if [ ! -z "`grep "${VM}" "${CONF}"`" ]; then
        echo "${IAM}: warning: JavaVM \"${VM}\" is already registered" 1>&2
        REGISTERED="yes"
    fi

    # Check that the VM exists and is "sane"
    if [ ! -e "${VM}" ]; then
        echo "${IAM}: error: JavaVM \"${VM}\" does not exist" 1>&2
        exit 1
    fi
    if [ -d "${VM}" ]; then
        echo "${IAM}: error: JavaVM \"${VM}\" is a directory" 1>&2
        exit 1
    fi
    if [ ! -x "${VM}" ]; then
        echo "${IAM}: error: JavaVM \"${VM}\" is not executable" 1>&2
        exit 1
    fi
    if [ `basename "${VM}"` != "java" ]; then
        echo "${IAM}: error: JavaVM \"${VM}\" is not valid" 1>&2
        exit 1
    fi
    if [ "`realpath "${VM}" 2>/dev/null `" = "${PREFIX}/bin/javavm" ]; then
        echo "${IAM}: error: JavaVM \"${VM}\" is javavm!" 1>&2
        exit 1
    fi

    # Add the VM to the configuration file
    if [ "${REGISTERED}" != "yes" ]; then
        echo "${1}" >> "${CONF}"
    fi

    # Create symbolic links as appropriate if they don't exist.
    JAVA_HOME=`dirname "${VM}"`
    JAVA_HOME=`dirname "${JAVA_HOME}"`
    createJavaLinks "${JAVA_HOME}"

    # Sort the VMs
    sortConfiguration

    exit 0
}

#
# Unregister a Java VM.
#
unregisterVM () {
    # Check usage
    if [ -z "${1}" ]; then
       echo "Usage: ${IAM} path"
       exit 1
    fi

    # Check for the configuration file
    if [ ! -e "${CONF}" ]; then
       echo "${IAM}: error: can't find ${CONF} configuration file!" >&2
       exit 1
    fi

    # Ensure the configuration file has the correct permissions
    if [ ! -w "${CONF}" -o ! -r "${CONF}" ]; then
        echo "${IAM}: error: can't read/write ${CONF} configuration file!" >&2
        exit 1
    fi

    # Check that the given VM can be found in the configuration file
    if [ -z "`grep "${1}" "${CONF}"`" ]; then
        echo "${IAM}: error: \"${1}\" JavaVM is not currently registered"
        exit 1
    fi

    # Remove unneeded symlinks
    VMS=`sed -E 's|[[:space:]]*#.*||' < "${CONF}" | uniq 2>/dev/null`
    VM=`grep "${1}" "${CONF}" | sed -E 's|[[:space:]]*#.*||' 2>/dev/null`
    JAVA_HOME=`dirname "${VM}"`
    JAVA_HOME=`dirname "${JAVA_HOME}"`
    for exe in "${JAVA_HOME}"/bin/* "${JAVA_HOME}"/jre/bin/*; do
        exe=`basename "${exe}"`
        if [ -L "${PREFIX}/bin/${exe}" -a \
             "`realpath "${PREFIX}/bin/${exe}" 2>/dev/null `" = \
             "${PREFIX}/bin/javavm" ]; then
            for JAVAVM in ${VMS}; do
                if [ "${JAVAVM}" != "${VM}" ]; then
                    JAVAVM=`dirname "${JAVAVM}"`
                    JAVAVM=`dirname "${JAVAVM}"`
                    if [ -x "${JAVAVM}/bin/${exe}" -o \
                         -x "${JAVAVM}/jre/bin/${exe}" ]; then
                        continue 2
                    fi
                fi
            done

            rm "${PREFIX}/bin/${exe}"
        fi
    done

    # Remove the VM from the configuration file
    ed "${CONF}" >/dev/null <<EOF
g|${1}|d
w
q
EOF

    # Remove configuration file if its size reached 0
    if [ ! -s "${CONF}" ]; then
        rm "${CONF}"
    fi

    exit 0
}

# Check for an alias and call the appropriate function.
case "${IAM}" in
    registervm )
        registerVM "${1}"
        ;;
    unregistervm )
        unregisterVM "${1}"
        ;;
    checkvms )
        checkVMs
        ;;
esac

# Main ()

# Backwards compatibility
if [ "${IAM}" = "javavm" ]; then
    echo "${IAM}: warning: The use of 'javavm' as a synonym for 'java' is deprecated" 1>&2
    IAM=java
fi

# Use JAVA_HOME if its set in the environment
if [ ! -z "${JAVA_HOME}" -a -x "${JAVA_HOME}/bin/${IAM}" ]; then
    export JAVA_HOME
    tryJavaCommand "${JAVA_HOME}/bin/${IAM}" "${@}"
elif [ ! -z "${JAVA_HOME}" -a -x "${JAVA_HOME}/jre/bin/${IAM}" ]; then
    export JAVA_HOME
    tryJavaCommand "${JAVA_HOME}/jre/bin/${IAM}" "${@}"
fi

unset JAVA_HOME

# Determine location of bsd.port.mk if it exists
PORTSDIR=
if [ -r /usr/share/mk/bsd.port.mk ]; then
    PORTSDIR=`"${MAKE}" -f /usr/share/mk/bsd.port.mk -V PORTSDIR 2>/dev/null`
fi

BSD_PORT_MK=
if [ ! -z "${PORTSDIR}" -a -r "${PORTSDIR}/Mk/bsd.port.mk" ]; then
    BSD_PORT_MK="${PORTSDIR}/Mk/bsd.port.mk"
fi

# If bsd.port.mk was found, use that to determine the VM to use.
if [ ! -z "${BSD_PORT_MK}" ]; then
    JAVA_HOME=`"${MAKE}" -f "${BSD_PORT_MK}" -V JAVA_HOME USE_JAVA=yes 2>/dev/null`
    if [ ! -z "${JAVA_HOME}" -a \
         -x "${JAVA_HOME}/bin/${IAM}" ]; then
        export JAVA_HOME
        tryJavaCommand "${JAVA_HOME}/bin/${IAM}" "${@}"
    elif [ ! -z "${JAVA_HOME}" -a \
           -x "${JAVA_HOME}/jre/bin/${IAM}" ]; then
        export JAVA_HOME
        tryJavaCommand "${JAVA_HOME}/jre/bin/${IAM}" "${@}"
    fi
fi

# Then try to make sure that ${CONF} exists
if [ ! -e "${CONF}" ]; then
    echo "${IAM}: error: can't find ${CONF} configuration file" >&2
    exit 1
fi

# Allow comments in the ${CONF}
VMS=`sed -E 's|[[:space:]]*#.*||' < "${CONF}" | uniq 2>/dev/null`

# Fix up JAVA_VERSION
if [ ! -z "${JAVA_VERSION}" ]; then
    VERSION=
    for version in ${JAVA_VERSION}; do
        case "${version}" in
            1.1+)
                VERSION="${VERSION} 1.1 1.2 1.3 1.4 1.5"
                ;;
            1.2+)
                VERSION="${VERSION} 1.2 1.3 1.4 1.5"
                ;;
            1.3+)
                VERSION="${VERSION} 1.3 1.4 1.5"
                ;;
            1.4+)
                VERSION="${VERSION} 1.4 1.5"
                ;;
            1.5+)
                VERSION="${VERSION} 1.5"
                ;;
            *)
                VERSION="${VERSION} ${version}"
                ;;
        esac
    done
    JAVA_VERSION=`echo "${VERSION}" | sort | uniq`
fi

# Finally try to run one of the ${VMS}
for JAVAVM in ${VMS}; do
    JAVA_HOME=`dirname "${JAVAVM}"`
    JAVA_HOME=`dirname "${JAVA_HOME}"`
    VM=`basename "${JAVA_HOME}"`
    # Respect JAVA_VERSION
    if [ ! -z "${JAVA_VERSION}" ]; then
        VERSION=`echo ${VM} | \
            sed -e 's|[^0-9]*\([0-9]\)\.\([0-9]\)\.[0-9]|\1.\2|'`
        for version in ${JAVA_VERSION}; do
            if [ "${VERSION}" = "${version}" ]; then
                VERSION=
                break
            fi
        done
        if [ ! -z "${VERSION}" ]; then
            continue
        fi
    fi
    # Respect JAVA_OS
    if [ ! -z "${JAVA_OS}" ]; then
        OS=
        case "${VM}" in
            diablo*|j*)
                OS=native
                ;;
            linux*)
                OS=linux
                ;;
        esac
        for os in ${JAVA_OS}; do
            if [ "${OS}" = "${os}" ]; then
                OS=
                break
            fi
        done
        if [ ! -z "${OS}" ]; then
            continue
        fi
    fi
    # Respect JAVA_VENDOR
    if [ ! -z "${JAVA_VENDOR}" ]; then
        VENDOR=
        case "${VM}" in
            diablo*)
                VENDOR=bsdjava
                ;;
            j*)
                VENDOR=freebsd
                ;;
            linux-blackdown*)
                VENDOR=blackdown
                ;;
            linux-ibm*)
                VENDOR=ibm
                ;;
            linux-sun*)
                VENDOR=sun
                ;;
        esac
        for vendor in ${JAVA_VENDOR}; do
            if [ "${VENDOR}" = "${vendor}" ]; then
                VENDOR=
                break
            fi
        done
        if [ ! -z "${VENDOR}" ]; then
            continue
        fi
    fi
    # Check if the command exists and try to run it.
    if [ ! -z "${JAVA_HOME}" -a \
         -x "${JAVA_HOME}/bin/${IAM}" ]; then
        export JAVA_HOME
        tryJavaCommand "${JAVA_HOME}/bin/${IAM}" "${@}"
    elif [ ! -z "${JAVA_HOME}" -a \
           -x "${JAVA_HOME}/jre/bin/${IAM}" ]; then
        export JAVA_HOME
        tryJavaCommand "${JAVA_HOME}/jre/bin/${IAM}" "${@}"
    fi
done

echo "${IAM}: error: no suitable JavaVMs found" >&2
exit 1
