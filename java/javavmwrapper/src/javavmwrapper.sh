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

_JAVAVM_SAVE_PATH=${PATH}
export PATH=/bin:/sbin:/usr/bin:/usr/sbin

_JAVAVM_PREFIX="%%PREFIX%%"
_JAVAVM_CONF="${_JAVAVM_PREFIX}/etc/javavms"
_JAVAVM_OPTS_CONF="${_JAVAVM_PREFIX}/etc/javavm_opts.conf"
_JAVAVM_PROG=`basename "${0}"`
_JAVAVM_MAKE=/usr/bin/make

#
# Try to run a Java command.
#
tryJavaCommand () {
    # If this is a test run, spit out the configuration and exit
    if [ -n "${JAVAVM_DRYRUN}" ]; then
        echo "JAVA_HOME=${JAVA_HOME}"
        echo "JAVAVM_CONF=${_JAVAVM_CONF}"
        echo "JAVAVM_OPTS_CONF=${_JAVAVM_OPTS_CONF}"
        echo "JAVAVM_PROG=${1}"
        echo "JAVAVM_OPTS=${_JAVAVM_OPTS}"
        echo "JAVAVM_COMMAND=${@}"
        exit 0
    fi

    # Check for the command being executable and exec it if so.
    if [ -x "${1}" ]; then
        if [ -n "${_JAVAVM_SAVE_PATH}" ]; then
            export PATH=${_JAVAVM_SAVE_PATH}
        fi
        exec "${@}"
    fi

    echo "${_JAVAVM_PROG}: warning: couldn't run specified Java command - \"${1}\"" 1>&2
}

#
# Set java command options, if applicable
# 1 - Name of the java programme to be executed.
# 2 - Base directory of JAVA_HOME for the java programme to be executed.
#
setJavaOptions () {
    local OPTS_PROG=`echo ${1} | sed -e s/\\\\./_/g -e s/-/_/g`
    local OPTS_JAVA_HOME=`echo ${2} | sed -e s/\\\\./_/g -e s/-/_/g`
    local JAVA_HOME_PROG_OPTS="`eval echo \$\{JAVAVM_OPTS_${OPTS_JAVA_HOME}_${OPTS_PROG}\} 2>/dev/null`"
    local JAVA_HOME_OPTS="`eval echo \$\{JAVAVM_OPTS_${OPTS_JAVA_HOME}\} 2>/dev/null`"
    local PROG_OPTS="`eval echo \$\{JAVAVM_OPTS_${OPTS_PROG}\} 2>/dev/null`"

    # Possible environment variables are stackable
    if [ -n "${JAVA_HOME_PROG_OPTS}" ]; then
        _JAVAVM_OPTS="${JAVA_HOME_PROG_OPTS} ${_JAVAVM_OPTS}"
    fi
    if [ -n "${JAVA_HOME_OPTS}" ]; then
        _JAVAVM_OPTS="${JAVA_HOME_OPTS} ${_JAVAVM_OPTS}"
    fi
    if [ -n "${PROG_OPTS}" ]; then
        _JAVAVM_OPTS="${PROG_OPTS} ${_JAVAVM_OPTS}"
    fi
    if [ -n "${JAVAVM_OPTS}" ]; then
        _JAVAVM_OPTS="${JAVAVM_OPTS} ${_JAVAVM_OPTS}"
    fi
}

#
# Create symbolic links for all of a Java VMs executables.
#
createJavaLinks () {
    for exe in "${1}"/bin/* "${1}"/jre/bin/*; do
        if [ -x "${exe}" -a \
             ! -d "${exe}" -a \
             "`basename "${exe}"`" = "`basename "${exe}" .so`" -a \
             ! -e "${_JAVAVM_PREFIX}/bin/`basename "${exe}"`" -a \
             -w "${_JAVAVM_PREFIX}/bin" ]; then
            ln -s "${_JAVAVM_PREFIX}/bin/javavm" \
                "${_JAVAVM_PREFIX}/bin/`basename "${exe}"`" 2>/dev/null
        fi
    done
}

#
# Sort the configuration file
#
sortConfiguration () {
    local IFS=:

    # Ensure the configuration file exists
    if [ ! -f "${_JAVAVM_CONF}" ]; then
        return
    fi

    # Ensure the configuration file has the correct permissions
    if [ ! -w "${_JAVAVM_CONF}" -o ! -r "${_JAVAVM_CONF}" ]; then
        echo "${_JAVAVM_PROG}: error: can't read/write ${_JAVAVM_CONF} configuration file!" 1>&2
        return
    fi

    cat "${_JAVAVM_CONF}" | \
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
        if [ "`realpath "${VM}" 2>/dev/null `" = "${_JAVAVM_PREFIX}/bin/javavm" ]; then
            continue
        fi
        # Skip duplicate VMs
        if [ -n "${JAVAVMS}" ]; then
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
                    diablo-jre*|openjdk*)
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
                    jdk*)
                        case "${_VM}" in
                            diablo*|open*)
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
                            diablo*|open*|j*)
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
                            diablo*|open*|j*|linux-sun*)
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
                            diablo*|open*|j*|linux-sun*|linux-blackdown*)
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
        if [ -n "${JAVAVM}" ]; then
            JAVAVMS="${JAVAVMS}:${JAVAVM}"
        fi
    done;
    if [ -n "${JAVAVMS}" ]; then
        rm "${_JAVAVM_CONF}"
        for JAVAVM in ${JAVAVMS}; do
            if [ -n "${JAVAVM}" ]; then
                echo "${JAVAVM}" >> "${_JAVAVM_CONF}"
            fi
        done
    fi
    )
}

#
# Check all of the VMs in the configuration file
#
checkVMs () {
    # Ensure the configuration file exists
    if [ ! -f "${_JAVAVM_CONF}" ]; then
        exit 0
    fi

    # Ensure the configuration file has the correct permissions
    if [ ! -w "${_JAVAVM_CONF}" -o ! -r "${_JAVAVM_CONF}" ]; then
        echo "${_JAVAVM_PROG}: error: can't read/write ${_JAVAVM_CONF} configuration file!" 1>&2
        exit 1
    fi

    # Sort the configuration.  This will also remove duplicates and
    # non-existent VMs
    sortConfiguration

    # Ensure links are created for every executable for a VM.
    cat "${_JAVAVM_CONF}" | \
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
       echo "Usage: ${_JAVAVM_PROG} path"
       exit 1
    fi

    # Create the configuration file if it doesn't exist
    if [ ! -e "${_JAVAVM_CONF}" ]; then
       touch "${_JAVAVM_CONF}"
    fi

    # Ensure the configuration file exists and has the correct permissions
    if [ ! -f "${_JAVAVM_CONF}" -o ! -w "${_JAVAVM_CONF}" -o ! -r "${_JAVAVM_CONF}" ]; then
        echo "${_JAVAVM_PROG}: error: can't read/write ${_JAVAVM_CONF} configuration file!" 1>&2
        exit 1
    fi

    # Check that the given VM can be found in the configuration file
    VM=`echo "${1}" | sed -E 's|[[:space:]]*#.*||' 2>/dev/null`
    REGISTERED=
    if [ -n "`grep "${VM}" "${_JAVAVM_CONF}"`" ]; then
        echo "${_JAVAVM_PROG}: warning: JavaVM \"${VM}\" is already registered" 1>&2
        REGISTERED="yes"
    fi

    # Check that the VM exists and is "sane"
    if [ ! -e "${VM}" ]; then
        echo "${_JAVAVM_PROG}: error: JavaVM \"${VM}\" does not exist" 1>&2
        exit 1
    fi
    if [ -d "${VM}" ]; then
        echo "${_JAVAVM_PROG}: error: JavaVM \"${VM}\" is a directory" 1>&2
        exit 1
    fi
    if [ ! -x "${VM}" ]; then
        echo "${_JAVAVM_PROG}: error: JavaVM \"${VM}\" is not executable" 1>&2
        exit 1
    fi
    if [ `basename "${VM}"` != "java" ]; then
        echo "${_JAVAVM_PROG}: error: JavaVM \"${VM}\" is not valid" 1>&2
        exit 1
    fi
    if [ "`realpath "${VM}" 2>/dev/null `" = "${_JAVAVM_PREFIX}/bin/javavm" ]; then
        echo "${_JAVAVM_PROG}: error: JavaVM \"${VM}\" is javavm!" 1>&2
        exit 1
    fi

    # Add the VM to the configuration file
    if [ "${REGISTERED}" != "yes" ]; then
        echo "${1}" >> "${_JAVAVM_CONF}"
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
       echo "Usage: ${_JAVAVM_PROG} path"
       exit 1
    fi

    # Check for the configuration file
    if [ ! -e "${_JAVAVM_CONF}" ]; then
       echo "${_JAVAVM_PROG}: error: can't find ${_JAVAVM_CONF} configuration file!" 1>&2
       exit 1
    fi

    # Ensure the configuration file has the correct permissions
    if [ ! -w "${_JAVAVM_CONF}" -o ! -r "${_JAVAVM_CONF}" ]; then
        echo "${_JAVAVM_PROG}: error: can't read/write ${_JAVAVM_CONF} configuration file!" 1>&2
        exit 1
    fi

    # Check that the given VM can be found in the configuration file
    if [ -z "`grep "${1}" "${_JAVAVM_CONF}"`" ]; then
        echo "${_JAVAVM_PROG}: error: \"${1}\" JavaVM is not currently registered"
        exit 1
    fi

    # Remove unneeded symlinks
    VMS=`sed -E 's|[[:space:]]*#.*||' < "${_JAVAVM_CONF}" | uniq 2>/dev/null`
    VM=`grep "${1}" "${_JAVAVM_CONF}" | sed -E 's|[[:space:]]*#.*||' 2>/dev/null`
    JAVA_HOME=`dirname "${VM}"`
    JAVA_HOME=`dirname "${JAVA_HOME}"`
    for exe in "${JAVA_HOME}"/bin/* "${JAVA_HOME}"/jre/bin/*; do
        exe=`basename "${exe}"`
        if [ -L "${_JAVAVM_PREFIX}/bin/${exe}" -a \
             "`realpath "${_JAVAVM_PREFIX}/bin/${exe}" 2>/dev/null `" = \
             "${_JAVAVM_PREFIX}/bin/javavm" ]; then
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

            rm "${_JAVAVM_PREFIX}/bin/${exe}"
        fi
    done

    # Remove the VM from the configuration file
    ed "${_JAVAVM_CONF}" >/dev/null <<EOF
g|${1}|d
w
q
EOF

    # Remove configuration file if its size reached 0
    if [ ! -s "${_JAVAVM_CONF}" ]; then
        rm "${_JAVAVM_CONF}"
    fi

    exit 0
}

#
# Show the manual page for a Java VM
#
manualpageVM () {
    # Check usage
    if [ -z "${1}" ]; then
       echo "Usage: ${_JAVAVM_PROG} name"
       exit 1
    fi

    # Look for an appropriate JAVA_HOME
    _JAVAVM_SAVE_PROG=${_JAVAVM_PROG}
    _JAVAVM_PROG="../man/man1/${1}.1"
    setJavaHome
    if [ $? != 0 ]; then
        echo "${_JAVAVM_SAVE_PROG}: error: no suitable JavaVMs found" 1>&2
        exit 1
    fi

    # Run man(1)
    MANPATH="${JAVA_HOME}/man:${MANPATH}"
    export MANPATH
    if [ "${LANG}" = "ja_JP.eucJP" -a -x "${_JAVAVM_PREFIX}/bin/jman" ]; then
	setJavaOptions jman "`basename ${JAVA_HOME}`"
	exec ${_JAVAVM_PREFIX}/bin/jman -S 1 ${_JAVAVM_OPTS} ${1}
    else
	setJavaOptions man "`basename ${JAVA_HOME}`"
	exec man -S 1 ${_JAVAVM_OPTS} ${1}
    fi
}

#
# Set up an appropriate JAVA_HOME
#
setJavaHome() {
    # Use JAVA_HOME if it's set, unless its set to %%PREFIX%%
    if [ -n "${JAVA_HOME}" ]; then
        if [ "`realpath "${JAVA_HOME}"`" != "`realpath "${_JAVAVM_PREFIX}"`" ]; then
	    if [ -f "${JAVA_HOME}/bin/${_JAVAVM_PROG}" ]; then
		_JAVAVM_PROG_PATH="${JAVA_HOME}/bin"
		return 0
	    elif [ -f "${JAVA_HOME}/jre/bin/${_JAVAVM_PROG}" ]; then
		_JAVAVM_PROG_PATH="${JAVA_HOME}/jre/bin"
		return 0
	    fi
	fi
    fi

    unset JAVA_HOME

    # Determine location of bsd.port.mk if it exists
    _JAVAVM_PORTSDIR=
    if [ -r /usr/share/mk/bsd.port.mk ]; then
        _JAVAVM_PORTSDIR=`"${_JAVAVM_MAKE}" -f /usr/share/mk/bsd.port.mk -V PORTSDIR 2>/dev/null`
    fi

    _JAVAVM_BSD_PORT_MK=
    if [ -n "${_JAVAVM_PORTSDIR}" -a -r "${_JAVAVM_PORTSDIR}/Mk/bsd.port.mk" ]; then
        _JAVAVM_BSD_PORT_MK="${_JAVAVM_PORTSDIR}/Mk/bsd.port.mk"
    fi

    # If bsd.port.mk was found, use that to determine the VM to use.
    if [ -n "${_JAVAVM_BSD_PORT_MK}" ]; then
        JAVA_HOME=`"${_JAVAVM_MAKE}" -f "${_JAVAVM_BSD_PORT_MK}" -V JAVA_HOME USE_JAVA=yes 2>/dev/null`
        if [ -n "${JAVA_HOME}" -a -f "${JAVA_HOME}/bin/${_JAVAVM_PROG}" ]; then
            _JAVAVM_PROG_PATH="${JAVA_HOME}/bin"
            return 0
        elif [ -n "${JAVA_HOME}" -a \
               -f "${JAVA_HOME}/jre/bin/${_JAVAVM_PROG}" ]; then
            _JAVAVM_PROG_PATH="${JAVA_HOME}/jre/bin"
            return 0
        fi
    fi

    # Then try to make sure that ${_JAVAVM_CONF} exists
    if [ ! -e "${_JAVAVM_CONF}" ]; then
        echo "${_JAVAVM_PROG}: error: can't find ${_JAVAVM_CONF} configuration file" 1>&2
        exit 1
    fi

    # Allow comments in the ${_JAVAVM_CONF}
    _JAVAVM_VMS=`sed -E 's|[[:space:]]*#.*||' < "${_JAVAVM_CONF}" | uniq 2>/dev/null`

    # Fix up JAVA_VERSION
    if [ -n "${JAVA_VERSION}" ]; then
        _JAVAVM_VERSION=
        for version in ${JAVA_VERSION}; do
            case "${version}" in
                1.1+)
                    _JAVAVM_VERSION="${_JAVAVM_VERSION} 1.1 1.2 1.3 1.4 1.5 1.6 1.7"
                    ;;
                1.2+)
                    _JAVAVM_VERSION="${_JAVAVM_VERSION} 1.2 1.3 1.4 1.5 1.6 1.7"
                    ;;
                1.3+)
                    _JAVAVM_VERSION="${_JAVAVM_VERSION} 1.3 1.4 1.5 1.6 1.7"
                    ;;
                1.4+)
                    _JAVAVM_VERSION="${_JAVAVM_VERSION} 1.4 1.5 1.6 1.7"
                    ;;
                1.5+)
                    _JAVAVM_VERSION="${_JAVAVM_VERSION} 1.5 1.6 1.7"
                    ;;
                1.6+)
                    _JAVAVM_VERSION="${_JAVAVM_VERSION} 1.6 1.7"
                    ;;
                1.6+)
                    _JAVAVM_VERSION="${_JAVAVM_VERSION} 1.7"
                    ;;
                *)
                    _JAVAVM_VERSION="${_JAVAVM_VERSION} ${version}"
                    ;;
            esac
        done
        JAVA_VERSION=`echo "${_JAVAVM_VERSION}" | sort | uniq`
    fi

    # Finally try to run one of the ${_JAVAVM_VMS}
    for _JAVAVM_JAVAVM in ${_JAVAVM_VMS}; do
        JAVA_HOME=`dirname "${_JAVAVM_JAVAVM}"`
        JAVA_HOME=`dirname "${JAVA_HOME}"`
        _JAVAVM_VM=`basename "${JAVA_HOME}"`
        # Respect JAVA_VERSION
        if [ -n "${JAVA_VERSION}" ]; then
            _JAVAVM_VERSION=`echo ${_JAVAVM_VM} | \
                sed -e 's|^[^0-9]*\([0-9]\)\.\([0-9]\)\.[0-9]$|\1.\2|' \
		    -e 's|^[^0-9]*\([0-9]\)$|1.\1|'`
            for _JAVAVM_REQUESTED_VERSION in ${JAVA_VERSION}; do
                if [ "${_JAVAVM_VERSION}" = "${_JAVAVM_REQUESTED_VERSION}" ]; then
                    _JAVAVM_VERSION=
                    break
                fi
            done
            if [ -n "${_JAVAVM_VERSION}" ]; then
                continue
            fi
        fi
        # Respect JAVA_OS
        if [ -n "${JAVA_OS}" ]; then
            _JAVAVM_OS=
            case "${_JAVAVM_VM}" in
                diablo*|j*)
                    _JAVAVM_OS=native
                    ;;
                linux*)
                    _JAVAVM_OS=linux
                    ;;
            esac
            for _JAVAVM_REQUESTED_OS in ${JAVA_OS}; do
                if [ "${_JAVAVM_OS}" = "${_JAVAVM_REQUESTED_OS}" ]; then
                    _JAVAVM_OS=
                    break
                fi
            done
            if [ -n "${_JAVAVM_OS}" ]; then
                continue
            fi
        fi
        # Respect JAVA_VENDOR
        if [ -n "${JAVA_VENDOR}" ]; then
            _JAVAVM_VENDOR=
            case "${_JAVAVM_VM}" in
                linux-blackdown*)
                    _JAVAVM_VENDOR=blackdown
                    ;;
                diablo*)
                    _JAVAVM_VENDOR=freebsd
                    ;;
                j*)
                    _JAVAVM_VENDOR=bsdjava
                    ;;
                linux-ibm*)
                    _JAVAVM_VENDOR=ibm
                    ;;
                openjdk*)
                    _JAVAVM_VENDOR=openjdk
                    ;;
                linux-sun*)
                    _JAVAVM_VENDOR=sun
                    ;;
            esac
            for _JAVAVM_REQUESTED_VENDOR in ${JAVA_VENDOR}; do
                if [ "${_JAVAVM_VENDOR}" = "${_JAVAVM_REQUESTED_VENDOR}" ]; then
                    _JAVAVM_VENDOR=
                    break
                fi
            done
            if [ -n "${_JAVAVM_VENDOR}" ]; then
                continue
            fi
        fi
        # Check if the command exists
        if [ -n "${JAVA_HOME}" -a -f "${JAVA_HOME}/bin/${_JAVAVM_PROG}" ]; then
            _JAVAVM_PROG_PATH="${JAVA_HOME}/bin"
            return 0
        elif [ -n "${JAVA_HOME}" -a \
               -f "${JAVA_HOME}/jre/bin/${_JAVAVM_PROG}" ]; then
            _JAVAVM_PROG_PATH="${JAVA_HOME}/jre/bin"
            return 0
        fi
    done

    unset JAVA_HOME

    return 1
}

# Check for an alias and call the appropriate function.
case "${_JAVAVM_PROG}" in
    registervm )
        registerVM "${1}"
        ;;
    unregistervm )
        unregisterVM "${1}"
        ;;
    checkvms )
        checkVMs
        ;;
    manvm )
        manualpageVM "${1}"
        ;;
esac

# Main ()

# Backwards compatibility
if [ "${_JAVAVM_PROG}" = "javavm" ]; then
    echo "${_JAVAVM_PROG}: warning: The use of 'javavm' as a synonym for 'java' is deprecated" 1>&2
    _JAVAVM_PROG=java
fi

# Initialise options
if [ -r "${_JAVAVM_OPTS_CONF}" ]; then
    . "${_JAVAVM_OPTS_CONF}"
fi
_JAVAVM_OPTS=

# Determine JAVA_HOME
setJavaHome
if [ $? != 0 ]; then
    echo "${_JAVAVM_PROG}: error: no suitable JavaVMs found" 1>&2
    exit 1
fi

# Set up the options and run the command
if [ -x "${_JAVAVM_PROG_PATH}/${_JAVAVM_PROG}" ]; then
    setJavaOptions "${_JAVAVM_PROG}" "`basename ${JAVA_HOME}`"
    export JAVA_HOME
    tryJavaCommand "${_JAVAVM_PROG_PATH}/${_JAVAVM_PROG}" ${_JAVAVM_OPTS} "${@}"
fi

echo "${_JAVAVM_PROG}: error: no suitable JavaVMs found" 1>&2
exit 1
