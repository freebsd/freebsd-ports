# New ports collection makefile for: vavoom
# Date created:		18 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	vavoom
PORTVERSION=	1.30
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Vavoom-source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doom, Doom II, Heretic, Hexen and Strife source port

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_CMAKE=	yes

OPTIONS=	ALLEGRO "Use Allegro for hardware API" off \
		FLAC "Enable FLAC support" off \
		LAUNCHER "Build GUI launcher" on \
		LIBMAD "Enable MP3 support" off \
		MIKMOD "Enable MikMod support" off \
		OPENAL "Enable OpenAL support" off \
		OPENGL "Enable OpenGL support" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" off \
		VORBIS "Enable Ogg Vorbis support" off \
		SDL "Use SDL for hardware API" on \
		WXUNICODE "Enable Unicode support" on

SUB_FILES=	pkg-message

BROKEN=		fails to build with new cmake.

.include <bsd.port.pre.mk>

# The `-fno-strict-aliasing' flag (default on FreeBSD 6.0+) produces
# non-working code for `vcc', so we remove it here if present.
CFLAGS:=	${CFLAGS:N-fno-strict-aliasing}
CXXFLAGS:=	${CFLAGS:N-fno-strict-aliasing}

.if !defined(WITH_ALLEGRO) && !defined(WITH_SDL)
IGNORE=		needs ALLEGRO or SDL for hardware API
.endif

.if defined(WITH_ALLEGRO) && defined(WITH_SDL)
IGNORE=		selected conflicting options ALLEGRO and SDL
.endif

.if defined(WITH_ALLEGRO)
LIB_DEPENDS+=	alleg.42:${PORTSDIR}/devel/allegro
CMAKE_ARGS+=	-DWITH_ALLEGRO=Y
.else
CMAKE_ARGS+=	-DWITH_ALLEGRO=N
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
CMAKE_ARGS+=	-DWITH_FLAC=Y
.else
CMAKE_ARGS+=	-DWITH_FLAC=N
.endif

.if defined(WITH_LAUNCHER)
USE_WX=		2.4+
CMAKE_ARGS+=	-DENABLE_LAUNCHER=Y \
		-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}"
PLIST_SUB+=	LAUNCHER=""
.else
CMAKE_ARGS+=	-DENABLE_LAUNCHER=N
PLIST_SUB+=	LAUNCHER="@comment "
.endif

.if defined(WITH_LIBMAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
CMAKE_ARGS+=	-DWITH_LIBMAD=Y
.else
CMAKE_ARGS+=	-DWITH_LIBMAD=N
.endif

.if defined(WITH_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
CMAKE_ARGS+=	-DWITH_MIKMOD=Y
.else
CMAKE_ARGS+=	-DWITH_MIKMOD=N
.endif

.if defined(WITH_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
CMAKE_ARGS+=	-DWITH_OPENAL=Y
.else
CMAKE_ARGS+=	-DWITH_OPENAL=N
.endif

.if defined(WITH_OPENGL)
USE_GL=		yes
. if defined(WITH_ALLEGRO)
LIB_DEPENDS+=	agl.0:${PORTSDIR}/graphics/allegrogl
BROKEN=		please use SDL instead of ALLEGRO, for OPENGL support
. endif
CMAKE_ARGS+=	-DWITH_OPENGL=Y
.else
CMAKE_ARGS+=	-DWITH_OPENGL=N
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CMAKE_ARGS+=	-DWITH_VORBIS=Y
.else
CMAKE_ARGS+=	-DWITH_VORBIS=N
.endif

.if defined(WITH_SDL)
USE_SDL=	mixer sdl
CMAKE_ARGS+=	-DWITH_SDL=Y
.else
CMAKE_ARGS+=	-DWITH_SDL=N
.endif

.if !defined(WITHOUT_WXUNICODE)
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

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/vavoom.txt ${DOCSDIR}
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include "${PORTSDIR}/games/doom-data/Makefile.include"

.include <bsd.port.post.mk>
