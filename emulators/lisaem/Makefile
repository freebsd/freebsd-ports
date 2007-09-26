# New ports collection makefile for:	lisaem
# Date created:		2007-07-04
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lisaem
DISTVERSION=	1.2.0
CATEGORIES=	emulators
MASTER_SITES=	http://lisa.sunder.net/20070923/

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
		${INSTALL_PROGRAM} ${WRKSRC}/bin/lisaem ${PREFIX}/bin
		${MKDIR} ${PREFIX}/share/LisaEm
		${INSTALL_DATA} ${WRKSRC}/resources/* ${PREFIX}/share/LisaEm/

.include <bsd.port.mk>
