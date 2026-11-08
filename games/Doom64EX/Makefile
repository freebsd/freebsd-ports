PORTNAME=	Doom64EX
DISTVERSION=	2.6-14
DISTVERSIONSUFFIX=	-g496d6e5
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Project aimed to recreate Doom64
WWW=		https://github.com/atsb/Doom64EX-Classic

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libpng.so:graphics/png

USES=		cmake gl sdl
USE_GITHUB=	yes
GH_ACCOUNT=	atsb
GH_PROJECT=	Doom64EX-Classic
USE_GL=		gl glu
USE_SDL=	sdl3

CMAKE_SOURCE_PATH=	${WRKSRC}/src

SUB_FILES=	pkg-message

DATADIR=	${PREFIX}/share/games/doom64

post-patch:
	${CP} ${FILESDIR}/CMakeLists.txt ${WRKSRC}/src

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/DOOM64 \
		${STAGEDIR}${PREFIX}/bin/doom64ex
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/WadGen \
		${STAGEDIR}${PREFIX}/bin/doom64ex-wadgen
	@${MKDIR} ${STAGEDIR}${DATADIR}/Content
	${INSTALL_DATA} ${WRKSRC}/src/wadgen/Content/* \
		${STAGEDIR}${DATADIR}/Content

.include <bsd.port.mk>
