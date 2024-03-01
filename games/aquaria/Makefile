PORTNAME=	aquaria
DISTVERSIONPREFIX=	OSE-v
DISTVERSION=	1.002-22
DISTVERSIONSUFFIX=	-g84366ad
PORTREVISION=	11
CATEGORIES=	games

PATCH_SITES=	https://github.com/AquariaOSE/Aquaria/commit/
PATCHFILES=	021512337ea0bee698e950e44222fb391ae7cb91.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Underwater 2D fantasy action-adventure (game engine)
WWW=		https://github.com/AquariaOSE/Aquaria

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libftgl.so:graphics/ftgl \
		libpng.so:graphics/png \
		libtinyxml2.so:textproc/tinyxml2

USES=		cmake:insource compiler:c++11-lang lua:51 openal pkgconfig sdl
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	AquariaOSE
GH_PROJECT=	Aquaria

CMAKE_ARGS=	-DAQUARIA_DEFAULT_DATA_DIR:PATH="${DATADIR}"
CMAKE_OFF=	AQUARIA_INTERNAL_FREETYPE \
		AQUARIA_INTERNAL_FTGL \
		AQUARIA_INTERNAL_LUA \
		AQUARIA_INTERNAL_OGGVORBIS \
		AQUARIA_INTERNAL_OPENAL \
		AQUARIA_INTERNAL_PNG \
		AQUARIA_INTERNAL_SDL \
		AQUARIA_INTERNAL_TINYXML2 \
		AQUARIA_INTERNAL_ZLIB

LDFLAGS+=	-Wl,--as-needed # avoid overlinking (vorbis deps)
LDFLAGS_i386=	-Wl,-z,notext -Wl,--no-check-dynamic-relocations

CXXFLAGS+=	-DGLM_ENABLE_EXPERIMENTAL  # GLM_GTX_transform is an experimental extension

DESKTOP_ENTRIES="${GH_PROJECT}" \
		"" \
		"${DATADIR}/${PORTNAME}.png" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ExternalLibs/,}
SUB_FILES=	pkg-message

PLIST_FILES=	bin/aquaria
PORTDATA=	*

OPTIONS_DEFINE=	SDL2
OPTIONS_DEFAULT=SDL2

SDL2_DESC=	Use SDL 2.x instead of SDL 1.2.x

SDL2_USE=	SDL=sdl2
SDL2_USE_OFF=	SDL=sdl
SDL2_CMAKE_BOOL=AQUARIA_USE_SDL2

EXCLUDE=	AL FTGL GL SDL* freetype2 glm glpng/png glpng/zlib \
		libogg-* libvorbis-* lua-* tinyxml2*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.for d in game_scripts files
	(cd ${WRKSRC}/${d} && ${COPYTREE_SHARE} \
		"." ${STAGEDIR}${DATADIR}/override)
.endfor

.include <bsd.port.mk>
