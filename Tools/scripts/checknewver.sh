#!/bin/sh
#
# checknewver
# Check for availability of the newest distfiles
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

display_warn () {
  if [ x"${SILENT}" != x"yes" ]; then
    echo "WARN: ${@}" >&2
  fi
}

display_err () {
  if [ x"${SILENT}" != x"yes" ]; then
    echo "ERROR: ${@}" >&2
  fi
  exit 1
}

display_msg () {
  if [ x"${SILENT}" != x"yes" ]; then
    echo "${@}" >&2
  fi
}

while getopts "s" COMMAND_LINE_ARGUMENT ; do
  case "${COMMAND_LINE_ARGUMENT}" in
  s)
    SILENT=yes
    ;;
  esac
done

if [ x`which ftpls` = x"" ]; then
  display_err "Couldn't find ftpls program, which is part of" \
    "ports/ftp/ftpcopy port. Please make sure that it is installed" \
    "and try again."
fi

if [ ! -e Makefile ]; then
  display_err "Couldn't find Makefile here."
fi

PORTNAME=`make -V PORTNAME 2>/dev/null`
PORTVERSION=`make -V PORTVERSION 2>/dev/null`
DISTFILES=`make -V DISTFILES 2>/dev/null`
if [ x"${PORTNAME}" = x"" -o x"${PORTVERSION}" = x"" -o x"${DISTFILES}" = x"" ]; then
  display_err "Either PORTNAME, PORTVERSION or DISTFILES is undefined in Makefile."
fi

MASTER_SITES=`env MASTER_SITE_BACKUP=\"\" make master-sites-all 2>/dev/null | xargs -n1 echo | grep ^ftp://`
if [ x"${MASTER_SITES}" = x"" ]; then
  display_err "Either MASTER_SITES is undefined in Makefile or it doesn't contain any ftp sites."
fi

display_msg "Checking for updated version of ${PORTNAME}..."
PV_PATR=`echo ${PORTVERSION} | sed 's=\.=\\\\.=g'`
for DISTNAME in ${DISTFILES}; do
  DF_PATR=`echo ${DISTNAME} | sed "s=${PV_PATR}=.*=" | \
    sed 's=\.=\\\\.=g ; s=\\\.\*=.*='`
  DF_CHECK=`echo ${DISTNAME} | sed 's=\.=\\\\.=g`
  if [ x"${DF_PATR}" = x"${DF_CHECK}" ]; then
    display_warn "Couldn't construct searching pattern - ${DISTNAME} ignored."
  else
    DF_PATRNS="${DF_PATRNS} ${DF_PATR}"
    F_DISTFILES="${F_DISTFILES} ${DISTNAME}"
  fi
done

if [ x"${F_DISTFILES}" = x"" ]; then
  display_warn "Nothing to check - exitting."
  exit 0
fi

DISTFILES="${F_DISTFILES}"

for MASTER_SITE in ${MASTER_SITES}; do
  display_msg "...checking ${MASTER_SITE}"
  FTPLIST=`ftpls ${MASTER_SITE} 2>/dev/null | grep -v ^dir | awk '{print $6}'`
  for DISTNAME in ${DISTFILES}; do
    DF_PATR=`echo ${DISTNAME} | sed "s=${PV_PATR}=.*=" | \
      sed 's=\.=\\\\.=g ; s=\\\.\*=.*='`
    for i in `echo ${FTPLIST} | xargs -n1 echo | grep "${DF_PATR}$"` ; do
      if [ "${i}" ">" "${DISTNAME}" ]; then
	NEW="${NEW} ${MASTER_SITE}${i}"
      fi
    done
  done
done

if [ x"${NEW}" != x"" ]; then
  display_msg ""
  display_msg "Hmm, is seems that there is newest version(s) at:"
  echo "${NEW}" | xargs -n1 echo
  display_msg ""
fi
