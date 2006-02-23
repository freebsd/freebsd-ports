# New ports collection makefile for:	quake2
# Date created:				20.01.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	quake2forge
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.galgenberg.net/distfiles/:qf \
		ftp://ftp.idsoftware.com/idstuff/quake2/source/:id \
		ftp://ftp.fasta.fh-dortmund.de/mirror/idstuff/quake2/source/:id
DISTNAME=	quake2-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:qf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	First Person Shooter with many addons available

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:259 libtool:15
USE_REINPLACE=	yes
WANT_SDL=	yes

CONFIGURE_ARGS=	--program-transform-name='s/^quake2$$/q2f/'
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

OPTIONS=	AO "Enable libao support" off \
		GL "Enable OpenGL support" on \
		ROGUE "Build Ground Zero (Rogue) mission pack" off \
		SDL "Enable SDL support" off \
		SVGA "Enable SVGAlib support" off \
		X11 "Enable X11 support" on \
		XATRIX "Build The Reckoning (Xatrix) mission pack" off

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_AO) || exists(${LOCALBASE}/lib/libao.so.3)
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao
CONFIGURE_ARGS+=--with-ao=${LOCALBASE}
PLIST_SUB+=	AO=""
.else
CONFIGURE_ARGS+=--without-ao
PLIST_SUB+=	AO="@comment "
.endif

.if defined(WITH_GL) || exists(${X11BASE}/lib/libGL.so.1)
USE_GL=		yes
CONFIGURE_ARGS+=--with-opengl=${X11BASE}
PLIST_SUB+=	GL=""
.else
CONFIGURE_ARGS+=--with-opengl=no
PLIST_SUB+=	GL="@comment "
.endif

.if defined(WITH_ROGUE)
DISTFILES+=	roguesrc320.shar.Z:id
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_rogue_g__local.h \
		${FILESDIR}/extra-patch-src_rogue_q__shared.c
Q2MP+=		rogue
ROGUE_OFF=	454
PLIST_SUB+=	ROGUE=""
.else
PLIST_SUB+=	ROGUE="@comment "
.endif

.if defined(WITH_SDL) || ${HAVE_SDL:Msdl}!=""
USE_SDL=	yes
CONFIGURE_ARGS+=--with-sdl=${LOCALBASE}
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--disable-sdl --disable-sdltest
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_GL) && (defined(WITH_SDL) || ${HAVE_SDL:Msdl}!="")
PLIST_SUB+=	SDLGL=""
.else
PLIST_SUB+=	SDLGL="@comment "
.endif

.if defined(WITH_SVGA) || exists(${LOCALBASE}/lib/libvga.so.1)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--with-svgalib=${LOCALBASE}
PLIST_SUB+=	SVGA=""
.else
CONFIGURE_ARGS+=--with-svgalib=no
PLIST_SUB+=	SVGA="@comment "
.endif

.if defined(WITH_X11) || exists(${X11BASE}/lib/libX11.so.6)
USE_XLIB=	yes
CONFIGURE_ARGS+=--with-x
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11="@comment "
.endif

.if defined(WITH_XATRIX)
DISTFILES+=	xatrixsrc320.shar.Z:id
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_xatrix_q__shared.c
Q2MP+=		xatrix
XATRIX_OFF=	441
PLIST_SUB+=	XATRIX=""
.else
PLIST_SUB+=	XATRIX="@comment "
.endif

post-extract:
.for mp in ${Q2MP}
	@${MKDIR} ${WRKSRC}/src/${mp}
	@(cd ${WRKSRC}/src/${mp} && ${GUNZIP_CMD} -c \
		${DISTDIR}/${DIST_SUBDIR}/${mp}src320.shar.Z > \
		${mp}src320.shar && \
		${TAIL} +${${mp:U}_OFF} ${mp}src320.shar | ${SH})
.endfor

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile.in -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e \
		's|\($$(libdir)/\)@PACKAGE@|\1${PORTNAME}|'
	@${REINPLACE_CMD} -e 's|\($$libdir/\)$$PACKAGE|\1${PORTNAME}|' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}.in
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's/%zu/%u/g' ${WRKSRC}/src/main.c
.endif

post-build:
.for mp in ${Q2MP}
	@(cd ${WRKSRC}/src/${mp}; ${MAKE} -f ${FILESDIR}/Makefile.${mp})
.endfor

post-install:
.for mp in ${Q2MP}
	${MKDIR} ${LIBDIR}/${mp}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${mp}/game.so ${LIBDIR}/${mp}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/ctf
	${INSTALL_DATA} ${WRKSRC}/docs/README.* ${WRKSRC}/docs/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/ctf/*.html ${WRKSRC}/docs/ctf/*.gif \
		${WRKSRC}/docs/ctf/*.jpg ${DOCSDIR}/ctf
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
