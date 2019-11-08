# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	vavoom
PORTVERSION=	1.33
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Vavoom-source/${PORTVERSION}

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Doom, Doom II, Heretic, Hexen, and Strife source port

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake:noninja dos2unix jpeg tar:bzip2
DOS2UNIX_REGEX=	((.*\.(c|cpp|h|s|asm|inc|vc|ls|acs|cfg|txt|vs|mak|mgw"))$$|\/(makefile\..*|makefile|Makefile)$$)

OPTIONS_DEFINE=	FLAC LAUNCHER MAD MIKMOD OPENAL OPTIMIZED_CFLAGS VORBIS SDL DOCS
OPTIONS_DEFAULT=	OPENGL SDL
LAUNCHER_DESC=	Build GUI launcher
OPENAL_DESC=	Enable OpenAL support
SDL_DESC=	Use SDL for OpenGL support

SUB_FILES=	pkg-message

# The `-fno-strict-aliasing' flag (default on FreeBSD 6.0+) produces
# non-working code for `vcc', so we remove it here if present.
CFLAGS:=	${CFLAGS:N-fno-strict-aliasing}
CXXFLAGS:=	${CFLAGS:N-fno-strict-aliasing}

OPTIONS_SUB=				yes

FLAC_LIB_DEPENDS=			libFLAC.so:audio/flac
FLAC_CMAKE_ON=				-DWITH_FLAC:BOOL=ON
FLAC_CMAKE_OFF=				-DWITH_FLAC:BOOL=OFF

LAUNCHER_USE=				WX=2.8+
LAUNCHER_CMAKE_ON=			-DENABLE_LAUNCHER:BOOL=ON \
	-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}"
LAUNCHER_CMAKE_OFF=			-DENABLE_LAUNCHER:BOOL=OFF

MAD_LIB_DEPENDS=			libmad.so:audio/libmad
MAD_CMAKE_ON=				-DWITH_LIBMAD:BOOL=ON
MAD_CMAKE_OFF=				-DWITH_LIBMAD:BOOL=OFF

MIKMOD_LIB_DEPENDS=			libmikmod.so:audio/libmikmod
MIKMOD_CMAKE_ON=			-DWITH_MIKMOD:BOOL=ON
MIKMOD_CMAKE_OFF=			-DWITH_MIKMOD:BOOL=OFF

OPENAL_USES=				openal:al
OPENAL_CMAKE_ON=			-DWITH_OPENAL:BOOL=ON
OPENAL_CMAKE_OFF=			-DWITH_OPENAL:BOOL=OFF

VORBIS_LIB_DEPENDS=			libvorbis.so:audio/libvorbis
VORBIS_CMAKE_ON=			-DWITH_VORBIS:BOOL=ON
VORBIS_CMAKE_OFF=			-DWITH_VORBIS:BOOL=OFF

SDL_USES=				gl sdl
SDL_USE=				GL=glu SDL=mixer,sdl
SDL_CMAKE_ON=				-DWITH_SDL:BOOL=ON -DWITH_OPENGL:BOOL=ON
SDL_CMAKE_OFF=				-DWITH_SDL:BOOL=OFF -DWITH_OPENGL:BOOL=OFF

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -ffast-math -fomit-frame-pointer

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|$$\* ||; s|$${IWADDIR}|-iwaddir ${DMDIR} $$*|' \
		${WRKSRC}/source/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' \
		${WRKSRC}/utils/acc/parse.c
	@${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' \
		${WRKSRC}/utils/acc/strlist.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/vavoom.txt ${STAGEDIR}${DOCSDIR}
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vavoom.bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vavoom-dedicated.bin

.include "${PORTSDIR}/games/doom-data/Makefile.include"

.include <bsd.port.mk>
