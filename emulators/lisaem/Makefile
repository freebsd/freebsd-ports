# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lisaem
DISTVERSION=	1.2.6
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	http://lisaem.sunder.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apple Lisa 2 Emulator

BUILD_DEPENDS=	pngtopnm:${PORTSDIR}/graphics/netpbm

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_WX=		2.8

NO_STAGE=	yes
post-patch:
		${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" \
				 -e "s|wx-config|${WX_CONFIG}|g" ${WRKSRC}/build.sh
do-build:
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build.sh build

do-install:
		@# This file is a symlink to itself; result of mistyped command?
		${RM} -f ${WRKSRC}/resources/resources
		${INSTALL_PROGRAM} ${WRKSRC}/bin/lisaem ${PREFIX}/bin
		${MKDIR} ${PREFIX}/share/lisaem
		${INSTALL_DATA} ${WRKSRC}/resources/* ${PREFIX}/share/lisaem/
		${LN} -sf ${PREFIX}/share/lisaem ${PREFIX}/share/LisaEm

.include <bsd.port.mk>
