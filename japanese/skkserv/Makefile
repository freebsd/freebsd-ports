# New ports collection makefile for:	skkserv
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skkserv
PORTVERSION=	9.6
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
DISTNAME=	skk${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=Dictionary server for the SKK Japanese-input software

RUN_DEPENDS=	${LOCALBASE}/share/skk/${SKKJISYO}:${PORTSDIR}/japanese/skk-jisyo

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
WRKSRC=		${WRKDIR}/skk-${PORTVERSION}
GNU_CONFIGURE=	yes
MAKE_ARGS=	SUBDIRS='skkserv'
CONFIGURE_ARGS+=	--with-jisyo=${SKKJISYO} --libexecdir=${PREFIX}/sbin
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/skkserv.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/skkserv/skkserv ${PREFIX}/sbin
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
		${ECHO} "Installing ${STARTUP_SCRIPT} file."; \
		${ECHO_CMD} "#!/bin/sh" > ${STARTUP_SCRIPT}; \
		${ECHO_CMD} 'case $$1 in' >> ${STARTUP_SCRIPT}; \
		${ECHO_CMD} "start)" >> ${STARTUP_SCRIPT}; \
		${ECHO_CMD} "	if [ -f ${PREFIX}/sbin/skkserv ]; then" >> \
			${STARTUP_SCRIPT}; \
		${ECHO_CMD} "		${ECHO_CMD} -n ' skkserv'; ${PREFIX}/sbin/skkserv" >> \
			${STARTUP_SCRIPT}; \
		${ECHO_CMD} "	fi" >> ${STARTUP_SCRIPT}; \
		${ECHO_CMD} "	;;" >> ${STARTUP_SCRIPT}; \
		${ECHO_CMD} "stop)" >> ${STARTUP_SCRIPT}; \
		${ECHO_CMD} "	;;" >> ${STARTUP_SCRIPT}; \
		${ECHO_CMD} "*)" >> ${STARTUP_SCRIPT}; \
		${ECHO_CMD} '	${ECHO_CMD} "usage: $$0 {start|stop}" 1>&2' >> ${STARTUP_SCRIPT}; \
		${ECHO_CMD} "	;;" >> ${STARTUP_SCRIPT}; \
		${ECHO_CMD} 'esac' >> ${STARTUP_SCRIPT}; \
		${CHMOD} ${BINMODE} ${STARTUP_SCRIPT}; \
	fi

.include <bsd.port.mk>
