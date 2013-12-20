# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lisaem
DISTVERSION=	1.2.6
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	http://lisaem.sunder.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apple Lisa 2 Emulator

BUILD_DEPENDS=	pngtopnm:${PORTSDIR}/graphics/netpbm

LICENSE=	GPLv2 # (or later)

USE_BZIP2=	yes
USE_WX=		2.8

DESKTOP_ENTRIES="LisaEm" "" "${DATADIR}/lisa2icon.xpm" "${PORTNAME}" "" ""

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%WX_CONFIG%%|${WX_CONFIG}|g' ${WRKSRC}/build.sh

do-build:
	${FIND} ${WRKSRC} -type l -delete
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build.sh build

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} lisaem ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/resources && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR})
	${LN} -sf lisaem ${STAGEDIR}${PREFIX}/share/LisaEm

.include <bsd.port.mk>
