PORTNAME=	OpenLara
DISTVERSION=	g20210226
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Classic Tomb Raider open-source engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gl sdl
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	XProger
GH_TAGNAME=	b4b19f2
USE_SDL=	sdl2

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} 's|g++|${CXX} ${CXXFLAGS}|' \
		${WRKSRC}/src/platform/sdl2/build.sh

do-build:
	cd ${WRKSRC}/src/platform/sdl2 && ./build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/platform/sdl2/OpenLara \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
