# New ports collection makefile for: vavoom
# Date created:		18 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	vavoom
PORTVERSION=	1.26
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Doom, Doom II, Heretic, Hexen and Strife source port

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	ALLEGRO "Use Allegro for hardware API" off \
		EDITING "Install Doom and Vavoom editing tools" off \
		FLAC "Enable FLAC support" off \
		LAUNCHER "Build GUI launcher" on \
		LIBMAD "Enable MP3 support" off \
		MIKMOD "Enable MikMod support" off \
		OPENAL "Enable OpenAL support" off \
		OPENGL "Enable OpenGL support" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" off \
		VORBIS "Enable Ogg Vorbis support" off \
		SDL "Use SDL for hardware API" on

SUB_FILES=	${PORTNAME} pkg-message

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
LIB_DEPENDS+=	alleg.42:${PORTSDIR}/devel/allegro \
		agl.4:${PORTSDIR}/graphics/allegrogl
CONFIGURE_ARGS+=--with-allegro
.else
CONFIGURE_ARGS+=--without-allegro
.endif

.if defined(WITH_EDITING)
PLIST_SUB+=	EDITING=""
.else
PLIST_SUB+=	EDITING="@comment "
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC.7:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--with-flac
.else
CONFIGURE_ARGS+=--without-flac
.endif

.if defined(WITH_LAUNCHER)
USE_WX=		2.4+
WX_CONF_ARGS=	absolute
CONFIGURE_ARGS+=--enable-launcher
PLIST_SUB+=	LAUNCHER=""
.else
CONFIGURE_ARGS+=--disable-launcher
PLIST_SUB+=	LAUNCHER="@comment "
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
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-vorbis
.else
CONFIGURE_ARGS+=--without-vorbis
.endif

.if defined(WITH_SDL)
USE_SDL=	mixer sdl
CONFIGURE_ARGS+=--with-sdl
.else
CONFIGURE_ARGS+=--without-sdl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\.$$host_cpu||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@cd ${WRKSRC} && ${SH} fixunix.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.if defined(WITH_EDITING)
	${INSTALL_PROGRAM} ${WRKSRC}/utils/bin/* ${PREFIX}/libexec/${PORTNAME}
. for f in utils/editing progs
	${CP} -r ${WRKSRC}/${f} ${DATADIR}
	@${FIND} ${DATADIR}/${f:T} -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DATADIR}/${f:T} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
. endfor
	@${FIND} ${DATADIR}/progs -type f -name "Makefile*" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -i '' -Ee 's|^(VCC =).*|\1 vcc|'
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/vavoom.txt ${DOCSDIR}
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include "${PORTSDIR}/games/doom-data/Makefile.include"

.include <bsd.port.post.mk>
