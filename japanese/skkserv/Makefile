# New ports collection makefile for:	skkserv
# Version required:	9.6
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id$
#

DISTNAME=	skk9.6
PKGNAME=	ja-skkserv-9.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

MAINTAINER=	matusita@jp.freebsd.org

RUN_DEPENDS=	${PREFIX}/share/skk/${SKKJISYO}:${SKK_MASTERDIR}

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${.CURDIR}/../../japanese/skk-jisyo
WRKSRC=		${SKK_MASTERDIR}/work/skk-9.6
MAKE_ARGS=	SUBDIRS='skkserv'

STARTUP_SCRIPT= ${PREFIX}/etc/rc.d/skkserv.sh

do-extract:
	@${ECHO} "===>  Extracting depends on ${SKK_MASTERDIR}"
	@[ -d ${WRKDIR} ] || ${MKDIR} ${WRKDIR}
	@if [ ! -f ${SKK_MASTERDIR}/work/.extract_done ]; then \
		(cd ${SKK_MASTERDIR}; make extract) ;\
	fi
	@if [ ! -f ${SKK_MASTERDIR}/work/.configure_done ]; then \
		(cd ${SKK_MASTERDIR}; PREFIX=${PREFIX} make configure) ;\
	fi

post-install:
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
		${ECHO} "Installing ${STARTUP_SCRIPT} file."; \
		${ECHO} "#!/bin/sh" > ${STARTUP_SCRIPT}; \
		${ECHO} "if [ -f ${PREFIX}/sbin/skkserv ]; then" >> \
			${STARTUP_SCRIPT}; \
		${ECHO} "  echo -n ' skkserv'; ${PREFIX}/sbin/skkserv" >> \
			${STARTUP_SCRIPT}; \
		${ECHO} "fi" >> ${STARTUP_SCRIPT}; \
		chmod 755 ${STARTUP_SCRIPT}; \
	fi

.include <bsd.port.mk>
