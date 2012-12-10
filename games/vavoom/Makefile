# New ports collection makefile for: vavoom
# Date created:		18 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	vavoom
PORTVERSION=	1.33
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Vavoom-source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doom, Doom II, Heretic, Hexen, and Strife source port

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_CMAKE=	yes

OPTIONS_SINGLE=	HWAPI
OPTIONS_SINGLE_HWAPI=	ALLEGRO SDL
OPTIONS_DEFINE=	ALLEGRO FLAC LAUNCHER MAD MIKMOD OPENAL OPENGL OPTIMIZED_CFLAGS VORBIS SDL WXUNICODE DOCS
OPTIONS_DEFAULT=	OPENGL SDL WXUNICODE
ALLEGRO_DESC=	Use Allegro for hardware API
LAUNCHER_DESC=	Build GUI launcher
OPENAL_DESC=	Enable OpenAL support
SDL_DESC=	Use SDL for hardware API
WXUNICODE_DESC=	Enable Unicode support

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

# The `-fno-strict-aliasing' flag (default on FreeBSD 6.0+) produces
# non-working code for `vcc', so we remove it here if present.
CFLAGS:=	${CFLAGS:N-fno-strict-aliasing}
CXXFLAGS:=	${CFLAGS:N-fno-strict-aliasing}

.if ${PORT_OPTIONS:MALLEGRO}
LIB_DEPENDS+=	alleg.42:${PORTSDIR}/devel/allegro
CMAKE_ARGS+=	-DWITH_ALLEGRO=Y
.else
CMAKE_ARGS+=	-DWITH_ALLEGRO=N
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
CMAKE_ARGS+=	-DWITH_FLAC=Y
.else
CMAKE_ARGS+=	-DWITH_FLAC=N
.endif

.if ${PORT_OPTIONS:MLAUNCHER}
USE_WX=		2.4+
CMAKE_ARGS+=	-DENABLE_LAUNCHER=Y \
		-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}"
PLIST_SUB+=	LAUNCHER=""
.else
CMAKE_ARGS+=	-DENABLE_LAUNCHER=N
PLIST_SUB+=	LAUNCHER="@comment "
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
CMAKE_ARGS+=	-DWITH_LIBMAD=Y
.else
CMAKE_ARGS+=	-DWITH_LIBMAD=N
.endif

.if ${PORT_OPTIONS:MMIKMOD}
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
CMAKE_ARGS+=	-DWITH_MIKMOD=Y
.else
CMAKE_ARGS+=	-DWITH_MIKMOD=N
.endif

.if ${PORT_OPTIONS:MOPENAL}
USE_OPENAL=	al
CMAKE_ARGS+=	-DWITH_OPENAL=Y
.else
CMAKE_ARGS+=	-DWITH_OPENAL=N
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		yes
. if ${PORT_OPTIONS:MALLEGRO}
LIB_DEPENDS+=	agl.0:${PORTSDIR}/graphics/allegrogl
BROKEN=		please use SDL instead of ALLEGRO, for OPENGL support
. endif
CMAKE_ARGS+=	-DWITH_OPENGL=Y
.else
CMAKE_ARGS+=	-DWITH_OPENGL=N
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CMAKE_ARGS+=	-DWITH_VORBIS=Y
.else
CMAKE_ARGS+=	-DWITH_VORBIS=N
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	mixer sdl
CMAKE_ARGS+=	-DWITH_SDL=Y
.else
CMAKE_ARGS+=	-DWITH_SDL=N
.endif

.if ${PORT_OPTIONS:MWXUNICODE}
WX_UNICODE=yes
.endif

post-patch:
	@cd ${WRKSRC} && ${SH} fixunix.sh
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
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/vavoom.txt ${DOCSDIR}
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include "${PORTSDIR}/games/doom-data/Makefile.include"

.include <bsd.port.mk>
