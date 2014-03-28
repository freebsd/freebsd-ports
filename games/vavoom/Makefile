# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	vavoom
PORTVERSION=	1.33
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Vavoom-source/${PORTVERSION}

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Doom, Doom II, Heretic, Hexen, and Strife source port

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

USES=		cmake dos2unix tar:bzip2
DOS2UNIX_REGEX=	((.*\.(c|cpp|h|s|asm|inc|vc|ls|acs|cfg|txt|vs|mak|mgw"))$$|\/(makefile\..*|makefile|Makefile)$$)

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	FLAC LAUNCHER MAD MIKMOD OPENAL OPTIMIZED_CFLAGS VORBIS SDL WXUNICODE DOCS
OPTIONS_DEFAULT=	OPENGL SDL WXUNICODE
LAUNCHER_DESC=	Build GUI launcher
OPENAL_DESC=	Enable OpenAL support
SDL_DESC=	Use SDL for OpenGL support
WXUNICODE_DESC=	Enable Unicode support

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

# The `-fno-strict-aliasing' flag (default on FreeBSD 6.0+) produces
# non-working code for `vcc', so we remove it here if present.
CFLAGS:=	${CFLAGS:N-fno-strict-aliasing}
CXXFLAGS:=	${CFLAGS:N-fno-strict-aliasing}

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	libFLAC.so:${PORTSDIR}/audio/flac
CMAKE_ARGS+=	-DWITH_FLAC=Y
.else
CMAKE_ARGS+=	-DWITH_FLAC=N
.endif

.if ${PORT_OPTIONS:MLAUNCHER}
USE_WX=		2.8+
CMAKE_ARGS+=	-DENABLE_LAUNCHER=Y \
		-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}"
PLIST_SUB+=	LAUNCHER=""
.else
CMAKE_ARGS+=	-DENABLE_LAUNCHER=N
PLIST_SUB+=	LAUNCHER="@comment "
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=	libmad.so:${PORTSDIR}/audio/libmad
CMAKE_ARGS+=	-DWITH_LIBMAD=Y
.else
CMAKE_ARGS+=	-DWITH_LIBMAD=N
.endif

.if ${PORT_OPTIONS:MMIKMOD}
LIB_DEPENDS+=	libmikmod.so:${PORTSDIR}/audio/libmikmod
CMAKE_ARGS+=	-DWITH_MIKMOD=Y
.else
CMAKE_ARGS+=	-DWITH_MIKMOD=N
.endif

.if ${PORT_OPTIONS:MOPENAL}
USES+=		openal:al
CMAKE_ARGS+=	-DWITH_OPENAL=Y
.else
CMAKE_ARGS+=	-DWITH_OPENAL=N
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbis.so:${PORTSDIR}/audio/libvorbis
CMAKE_ARGS+=	-DWITH_VORBIS=Y
.else
CMAKE_ARGS+=	-DWITH_VORBIS=N
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	mixer sdl
CMAKE_ARGS+=	-DWITH_SDL=Y
USE_GL=		yes
CMAKE_ARGS+=	-DWITH_OPENGL=Y
.else
CMAKE_ARGS+=	-DWITH_SDL=N
CMAKE_ARGS+=	-DWITH_OPENGL=N
.endif

.if ${PORT_OPTIONS:MWXUNICODE}
WX_UNICODE=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$\* ||; s|$${IWADDIR}|-iwaddir ${DMDIR} $$*|' \
		${WRKSRC}/source/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' \
		${WRKSRC}/utils/acc/parse.c
	@${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' \
		${WRKSRC}/utils/acc/strlist.c

post-configure:
.if ${PORT_OPTIONS:MLAUNCHER}
	@${REINPLACE_CMD} -e 's/-pthread;-D_THREAD_SAFE //; \
			s/-isystem /-I/g' \
		${WRKSRC}/utils/vlaunch/CMakeFiles/vlaunch.dir/flags.make
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/vavoom.txt ${STAGEDIR}${DOCSDIR}
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vavoom.bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vavoom-dedicated.bin

.include "${PORTSDIR}/games/doom-data/Makefile.include"

.include <bsd.port.mk>
