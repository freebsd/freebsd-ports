#!/bin/sh
#
# A simple script to make man(1) behaviour more gnu'ish.
#
# $FreeBSD$
#

if [ x"${1}" = x"" ]; then
  exit
fi

if [ -f "${1}" ]; then
  COMPRESSED=`/usr/bin/file "${1}" | /usr/bin/grep "gzip compressed data"`
  CAT_CMD=/bin/cat
  if [ x"${COMPRESSED}" != x"" ]; then
    CAT_CMD=/usr/bin/gzcat
  fi
  ${CAT_CMD} "${1}" | /usr/bin/nroff -mandoc
else
  /usr/bin/man -P "/bin/cat" "${@}" 2>/dev/null
  ERRCODE=${?}
  if [ ${ERRCODE} != 0 ]; then
    /bin/echo "No such manpage!" >&2
    exit ${ERRCODE}
  fi
fi
