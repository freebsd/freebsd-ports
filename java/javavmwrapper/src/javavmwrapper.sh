#!/bin/sh
#
# javawrapper.sh
#
# Allows to install several Java Virtual Machines
# on the same system and use config file/or environment
# variable to select wichever to use
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
# $FreeBSD$
#
# MAINTAINER= sobomax@FreeBSD.org

ARGS="${*}"
PREFIX="%%PREFIX%%"
CONF="${PREFIX}/etc/javavms"
IAM=`basename "${0}"`

tryrunVM () {
    if [ -x "${1}" ]; then
        exec "${1}" ${2}
    fi

    /bin/echo "${IAM}: warning: couldn't start specified JavaVM - \"${1}\"" >&2
}

registerVM () {
    if [ x"${1}" = x"" ]; then
       /bin/echo "Usage: ${IAM} path"
       exit
    fi

    if [ ! -e "${CONF}" ]; then
       /usr/bin/touch "${CONF}"
    fi

    VM=`/bin/echo "${1}" | sed 's|#.*||'`
    if [ ! -x ${VM} ]; then
        /bin/echo "${IAM}: warning: the specified JavaVM \"${VM}\" either not exists or not executable" >&2
    fi

    /bin/ed "${CONF}" >/dev/null <<EOF
0a
${1}
.
w
q
EOF
    exit 0
}

unregisterVM () {
    if [ x"${1}" = x"" ]; then
       /bin/echo "Usage: ${IAM} path"
       exit
    fi

    if [ ! -e "${CONF}" ]; then
       /bin/echo "${IAM}: error: can't find ${CONF} config file!" >&2
       exit 1
    fi

    if [ x"`grep ${1} ${CONF}`" = x"" ]; then
        /bin/echo "${IAM}: error: \"${1}\" JavaVM is not currently registered"
        exit 1
    fi

    /bin/ed "${CONF}" >/dev/null <<EOF
g|${1}|d
w
q
EOF

    # Remove config file if its size reached 0
    if [ ! -s "${CONF}" ]; then
        /bin/rm "${CONF}"
    fi

    exit 0
}

case "${IAM}" in
    registervm )
        registerVM "${1}"
        ;;
    unregistervm )
        unregisterVM "${1}"
        ;;
esac

# Main ()

unset JAVA_HOME

# First check if JAVAVM environment variable is set
if [ x"${JAVAVM}" != x"" ]; then
    tryrunVM "${JAVAVM}" "${ARGS}"
fi

# Then try to make sure that ${CONF} exists
if [ ! -e "${CONF}" ]; then
    echo "${IAM}: error: can't find ${CONF} config file" >&2
    exit 1
fi

# Allow coment in the ${CONF}
VMS=`/usr/bin/sed 's|#.*||' < "${CONF}" | uniq`

# Finally try to run one of the ${VMS}
for JAVAVM in ${VMS}; do
    tryrunVM "${JAVAVM}" "${ARGS}";
done

echo "${IAM}: error: no suitable JavaVMs found" >&2
exit 1
