# New ports collection makefile for: vavoom
# Date created:		18 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	vavoom
PORTVERSION=	1.22.1
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Doom, Doom II, Heretic, Hexen and Strife source port

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GCC=	3.4+
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

OPTIONS=	ALLEGRO "Use Allegro for hardware API" off \
		DEVEL "Install development tools (Doom/Vavoom)" off \
		FLAC "Enable FLAC support" off \
		LIBMAD "Enable MP3 support" off \
		MIKMOD "Enable MikMod support" off \
		MODELS "Install 3D models for supported games" off \
		OPENAL "Enable OpenAL support" off \
		OPENGL "Enable OpenGL support" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" off \
		VORBIS "Enable Ogg Vorbis support" off \
		SDL "Use SDL for hardware API" on

SUB_FILES=	${PORTNAME} pkg-message

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/games/doom-data/Makefile.include"

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
LIB_DEPENDS+=	alleg.42:${PORTSDIR}/devel/allegro \
		agl.4:${PORTSDIR}/graphics/allegrogl
CONFIGURE_ARGS+=--with-allegro
.else
CONFIGURE_ARGS+=--without-allegro
.endif

.if defined(WITH_DEVEL)
PLIST_SUB+=	DEVEL=""
.else
PLIST_SUB+=	DEVEL="@comment "
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC.7:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--with-flac
.else
CONFIGURE_ARGS+=--without-flac
.endif

.if defined(WITH_LIBMAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=--with-libmad
.else
CONFIGURE_ARGS+=--without-libmad
.endif

.if defined(WITH_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
CONFIGURE_ARGS+=--with-mikmod
.else
CONFIGURE_ARGS+=--without-mikmod
.endif

.if defined(WITH_MODELS)
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.for f in doom heretic hexen strife
DISTFILES+=	vmdl_${f}_13.zip
.endfor
PLIST_SUB+=	MODELS=""
.else
PLIST_SUB+=	MODELS="@comment "
.endif

.if defined(WITH_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
CONFIGURE_ARGS+=--with-openal
.else
CONFIGURE_ARGS+=--without-openal
.endif

.if defined(WITH_OPENGL)
USE_GL=		yes
CONFIGURE_ARGS+=--with-opengl
.else
CONFIGURE_ARGS+=--without-opengl
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-vorbis
.else
CONFIGURE_ARGS+=--without-vorbis
.endif

.if defined(WITH_SDL)
USE_SDL=	mixer sdl
CONFIGURE_ARGS+=--with-sdl --with-sdl-config=${SDL_CONFIG}
.else
CONFIGURE_ARGS+=--without-sdl
.endif

.if defined(WITH_MODELS)
post-extract:
.for f in doom heretic hexen strife
	@${UNZIP_CMD} -aqo ${DISTDIR}/vmdl_${f}_13.zip -d ${WRKDIR}
.endfor
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/||g' ${WRKSRC}/source/s_sdl.cpp
	@${REINPLACE_CMD} -e 's|\.$$host_cpu||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e '/animated\.lmp/d' \
		${WRKSRC}/basev/doom/basepak.ls.in
	@cd ${WRKSRC} && ${SH} fixunix.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.if defined(WITH_DEVEL)
	${INSTALL_PROGRAM} ${WRKSRC}/utils/bin/* ${PREFIX}/libexec/${PORTNAME}
	${CP} -r ${WRKSRC}/utils/editing ${WRKSRC}/progs ${DATADIR}
	@${FIND} ${DATADIR}/progs -type f -name "Makefile*" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -i '' -Ee 's|^(VCC =).*|\1 vcc|'
.endif
.if defined(WITH_MODELS)
	${CP} -r ${WRKDIR}/basev ${DATADIR}
.endif
.if defined(WITH_DEVEL) || defined(WITH_MODELS)
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/vavoom.txt ${DOCSDIR}
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
