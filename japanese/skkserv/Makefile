# New ports collection makefile for:	skkserv
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skkserv
PORTVERSION=	9.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/${PORTVERSION}/
DISTNAME=	skk${PORTVERSION}

MAINTAINER=	matusita@jp.FreeBSD.org

BUILD_DEPENDS=	/nonexistent:${SKK_MASTERDIR}:configure
RUN_DEPENDS=	${PREFIX}/share/skk/${SKKJISYO}:${SKK_MASTERDIR}

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${.CURDIR}/../../japanese/skk-jisyo
WRKSRC=		${WRKDIRPREFIX}${SKK_MASTERDIR}/work/skk-${PORTVERSION}
MAKE_ARGS=	SUBDIRS='skkserv'

STARTUP_SCRIPT= ${PREFIX}/etc/rc.d/skkserv.sh

post-install:
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
		${ECHO} "Installing ${STARTUP_SCRIPT} file."; \
		${ECHO} "#!/bin/sh" > ${STARTUP_SCRIPT}; \
		${ECHO} 'case $$1 in' >> ${STARTUP_SCRIPT}; \
		${ECHO} "start)" >> ${STARTUP_SCRIPT}; \
		${ECHO} "	if [ -f ${PREFIX}/sbin/skkserv ]; then" >> \
			${STARTUP_SCRIPT}; \
		${ECHO} "		${ECHO} -n ' skkserv'; ${PREFIX}/sbin/skkserv" >> \
			${STARTUP_SCRIPT}; \
		${ECHO} "	fi" >> ${STARTUP_SCRIPT}; \
		${ECHO} "	;;" >> ${STARTUP_SCRIPT}; \
		${ECHO} "stop)" >> ${STARTUP_SCRIPT}; \
		${ECHO} "	;;" >> ${STARTUP_SCRIPT}; \
		${ECHO} "*)" >> ${STARTUP_SCRIPT}; \
		${ECHO} '	${ECHO} "usage: $$0 {start|stop}" 1>&2' >> ${STARTUP_SCRIPT}; \
		${ECHO} "	;;" >> ${STARTUP_SCRIPT}; \
		${ECHO} 'esac' >> ${STARTUP_SCRIPT}; \
		${CHMOD} ${BINMODE} ${STARTUP_SCRIPT}; \
	fi

.include <bsd.port.mk>
