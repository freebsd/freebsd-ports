#!/bin/sh
#
# checknewver
# Check for availability of the newest distfiles
#
# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42, (c) Poul-Henning Kamp):
# Maxim Sobolev <sobomax@altavista.net wrote this file.  As long as you retain
# this notice you can do whatever you want with this stuff. If we meet some
# day, and you think this stuff is worth it, you can buy me a beer in return.
#
# Maxim Sobolev
# ----------------------------------------------------------------------------
#
# $FreeBSD$
#
# MAINTAINER= sobomax@FreeBSD.org

if [ x`which ftpls` = x"" ]; then
  echo -n "ERROR: Couldn't find ftpls program, which is part of " >&2
  echo "ports/ftp/ftpcopy port." >&2
  echo "       Please make sure that it is installed and try again." >&2
  exit 1
fi

if [ ! -e Makefile ]; then
  echo "ERROR: Couldn't find Makefile here." >&2
  exit 1
fi

PORTNAME=`make -V PORTNAME`
PORTVERSION=`make -V PORTVERSION`
DISTFILES=`make -V DISTFILES`
if [ x"${PORTNAME}" = x"" -o x"${PORTVERSION}" = x"" -o x"${DISTFILES}" = x"" ]; then
  echo "ERROR: either PORTNAME, PORTVERSION or DISTFILES is undefined in Makefile." >&2
  exit 1
fi

MASTER_SITES=`env MASTER_SITE_BACKUP=\"\" make -V MASTER_SITES | xargs -n1 echo | grep ^ftp://`
if [ x"${MASTER_SITES}" = x"" ]; then
  echo "ERROR: either MASTER_SITES is undefined in Makefile or it doesn't contain any ftp sites." >&2
  exit 1
fi

echo "Checking for updated version of ${PORTNAME}..." >&2
PV_PATR=`echo ${PORTVERSION} | sed 's=\.=\\\\.=g'`
for DISTNAME in ${DISTFILES}; do
  DF_PATR=`echo ${DISTNAME} | sed "s=${PV_PATR}=.*=" | \
    sed 's=\.=\\\\.=g ; s=\\\.\*=.*='`
  DF_CHECK=`echo ${DISTNAME} | sed 's=\.=\\\\.=g`
  if [ x"${DF_PATR}" = x"${DF_CHECK}" ]; then
    echo "WARN: Couldn't construct searching pattern - ${DISTNAME} ignored." >&2
  else
    DF_PATRNS="${DF_PATRNS} ${DF_PATR}"
    F_DISTFILES="${F_DISTFILES} ${DISTNAME}"
  fi
done

if [ x"${F_DISTFILES}" = x"" ]; then
  echo "WARN: Nothing to check - exitting." >&2
  exit 0
fi

DISTFILES="${F_DISTFILES}"

for MASTER_SITE in ${MASTER_SITES}; do
  echo "...checking ${MASTER_SITE}" >&2
  FTPLIST=`ftpls ${MASTER_SITE} 2>/dev/null | grep -v ^dir | awk '{print $6}'`
  for DISTNAME in ${DISTFILES}; do
    DF_PATR=`echo ${DISTNAME} | sed "s=${PV_PATR}=.*=" | \
      sed 's=\.=\\\\.=g ; s=\\\.\*=.*='`
    for i in `echo ${FTPLIST} | xargs -n1 echo | grep "${DF_PATR}"` ; do
      if [ "${i}" ">" "${DISTNAME}" ]; then
	NEW="${NEW} ${MASTER_SITE}${i}"
      fi
    done
  done
done

if [ x"${NEW}" != x"" ]; then
  echo ""
  echo "Hmm, is seems that there is newest version(s) at:"
  echo "${NEW}" | xargs -n1 echo
  echo ""
fi
