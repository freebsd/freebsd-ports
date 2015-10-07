# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	goonies
PORTVERSION=	1.0.1
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://goonies.jorito.net/download/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_r${PORTVERSION:C/\./-/g}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Remake of the 8 bit classic game 'The Goonies'

BROKEN_sparc64=	does not compile on sparc64

USES=		gmake tar:tgz
USE_SDL=	sdl mixer image
USE_GL=		yes

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	../build/linux/Makefile
MAKE_ARGS=	CC="${CXX}"
MAKE_ENV=	DATADIR="${DATADIR}"

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|sound/|${DATADIR}/sound/|g' \
		${WRKSRC}/src/SFXManager.cpp
	@${REINPLACE_CMD} -e 's|graphics/|${DATADIR}/graphics/|g' \
		${WRKSRC}/src/GLTManager.cpp ${WRKSRC}/src/TheGooniesApp.cpp
	@${REINPLACE_CMD} -e 's|maps/|${DATADIR}/maps/|g' \
		${WRKSRC}/src/TheGoonies.cpp

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/goonies ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		'sound graphics maps' ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
