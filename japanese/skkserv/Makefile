# New ports collection makefile for:	skkserv
# Version required:	9.6
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1998/12/15 15:22:46 kuriyama Exp $
#

DISTNAME=	skk9.6
PKGNAME=	ja-skkserv-9.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

MAINTAINER=	matusita@jp.freebsd.org

BUILD_DEPENDS=	/nonexistent:${SKK_MASTERDIR}:configure
RUN_DEPENDS=	${PREFIX}/share/skk/${SKKJISYO}:${SKK_MASTERDIR}

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${.CURDIR}/../../japanese/skk-jisyo
WRKSRC=		${SKK_MASTERDIR}/work/skk-9.6
MAKE_ARGS=	SUBDIRS='skkserv'

STARTUP_SCRIPT= ${PREFIX}/etc/rc.d/skkserv.sh

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
