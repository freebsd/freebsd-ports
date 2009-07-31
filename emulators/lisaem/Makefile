# New ports collection makefile for:	lisaem
# Date created:		2007-07-04
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lisaem
DISTVERSION=	1.2.6
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://lisaem.sunder.net/downloads/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Apple Lisa 2 Emulator

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		pngtopnm:${PORTSDIR}/graphics/netpbm

USE_BZIP2=	yes
USE_WX=		2.8

post-patch:
		${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" \
				 -e "s|wx-config|${WX_CONFIG}|g" ${WRKSRC}/build.sh
do-build:
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/bash build.sh build

do-install:
		@# This file is a symlink to itself; result of mistyped command?
		${RM} -f ${WRKSRC}/resources/resources
		${INSTALL_PROGRAM} ${WRKSRC}/bin/lisaem ${PREFIX}/bin
		${MKDIR} ${PREFIX}/share/lisaem
		${INSTALL_DATA} ${WRKSRC}/resources/* ${PREFIX}/share/lisaem/
		${LN} -sf ${PREFIX}/share/lisaem ${PREFIX}/share/LisaEm

.include <bsd.port.mk>
