# $FreeBSD$

PORTNAME=	aquaria
DISTVERSIONPREFIX=	OSE-v
DISTVERSION=	1.002-22
DISTVERSIONSUFFIX=	-g84366ad
CATEGORIES=	games

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Underwater 2D fantasy action-adventure (game engine)

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libftgl.so:graphics/ftgl \
		libpng.so:graphics/png \
		libtinyxml2.so:textproc/tinyxml2

USE_GITHUB=	yes
GH_ACCOUNT=	AquariaOSE
GH_PROJECT=	Aquaria

USES=		cmake lua:51 openal pkgconfig
EXCLUDE=	AL FTGL GL SDL* freetype2 glm glpng/png glpng/zlib \
		libogg-* libvorbis-* lua-* tinyxml2*
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ExternalLibs/,}
CMAKE_ARGS+=	-DAQUARIA_DEFAULT_DATA_DIR="${DATADIR}" \
		-DAQUARIA_INTERNAL_FREETYPE=off \
		-DAQUARIA_INTERNAL_FTGL=off \
		-DAQUARIA_INTERNAL_LUA=off \
		-DAQUARIA_INTERNAL_OGGVORBIS=off \
		-DAQUARIA_INTERNAL_OPENAL=off \
		-DAQUARIA_INTERNAL_PNG=off \
		-DAQUARIA_INTERNAL_SDL=off \
		-DAQUARIA_INTERNAL_TINYXML2=off \
		-DAQUARIA_INTERNAL_ZLIB=off
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (vorbis deps)
SUB_FILES=	pkg-message
PLIST_FILES=	bin/aquaria
PORTDATA=	*

DESKTOP_ENTRIES="${GH_PROJECT}" \
		"" \
		"${DATADIR}/${PORTNAME}.png" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=	DEBUG SDL2
OPTIONS_DEFAULT=SDL2

SDL2_DESC=	Use SDL 2.x instead of SDL 1.2.x
SDL2_CMAKE_ON=	-DAQUARIA_USE_SDL2=on
SDL2_USE=	SDL=sdl2
SDL2_USE_OFF=	SDL=sdl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.for d in game_scripts files
	(cd ${WRKSRC}/${d} && ${COPYTREE_SHARE} \
		"." ${STAGEDIR}${DATADIR}/override)
.endfor

.include <bsd.port.mk>
