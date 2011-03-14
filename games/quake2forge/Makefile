# New ports collection makefile for:	quake2
# Date created:				20.01.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	quake2forge
PORTVERSION=	0.3
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	https://www.spoerlein.net/pub/
DISTNAME=	quake2-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	First Person Shooter with many addons available

USE_AUTOTOOLS=	autoconf libtool
USE_BZIP2=	yes

CONFIGURE_ARGS=	--program-transform-name='s/^quake2$$/${PORTNAME}/' \
		--disable-warn

OPTIONS=	AO "Build libao sound module" off \
		CTF "Build the CTF (Capture The Flag) modification" off \
		GAME "Build a main game .so file" off \
		GL "Build OpenGL renderer" on \
		SDL "Build SDL renderers" off \
		SVGA "Build SVGA renderer" off \
		X11 "Build X11 renderer" on

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_GL) || defined(WITH_X11)
USE_XORG=	xxf86dga
.endif

.if defined(WITH_AO)
LIB_DEPENDS+=	ao.4:${PORTSDIR}/audio/libao
CONFIGURE_ARGS+=--with-ao=${LOCALBASE}
PLIST_SUB+=	AO=""
.else
CONFIGURE_ARGS+=--without-ao
PLIST_SUB+=	AO="@comment "
.endif

.if defined(WITH_CTF)
PLIST_SUB+=	CTF=""
.else
Q2F_BADMODS+=	ctf
PLIST_SUB+=	CTF="@comment "
.endif

.if defined(WITH_GAME)
PLIST_SUB+=	GAME=""
.else
Q2F_BADMODS+=	baseq2
PLIST_SUB+=	GAME="@comment "
.endif

.if defined(WITH_GL)
USE_GL=		yes
CONFIGURE_ARGS+=--with-opengl=${LOCALBASE}
PLIST_SUB+=	GL=""
.else
CONFIGURE_ARGS+=--with-opengl=no
PLIST_SUB+=	GL="@comment "
.endif

.if defined(WITH_SDL)
USE_SDL=	yes
CONFIGURE_ARGS+=--with-sdl=${LOCALBASE}
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--disable-sdl --disable-sdltest
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_GL) && defined(WITH_SDL)
PLIST_SUB+=	SDLGL=""
.else
PLIST_SUB+=	SDLGL="@comment "
.endif

.if defined(WITH_SVGA)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--with-svgalib=${LOCALBASE}
PLIST_SUB+=	SVGA=""
.else
CONFIGURE_ARGS+=--with-svgalib=no
PLIST_SUB+=	SVGA="@comment "
.endif

.if defined(WITH_X11)
CONFIGURE_ARGS+=--with-x
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile.in -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e \
		's|\($$(libdir)/\)@PACKAGE@|\1${PORTNAME}|'
	@${REINPLACE_CMD} -e 's|\($$libdir/\)$$PACKAGE|\1${PORTNAME}|' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}.in
.for f in ${Q2F_BADMODS}
	@${REINPLACE_CMD} -i "" -e 's/${f}//' ${WRKSRC}/src/Makefile.in
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README.* ${WRKSRC}/docs/*.txt ${DOCSDIR}
.if defined(WITH_CTF)
	${MKDIR} ${DOCSDIR}/ctf
.for f in *.html *.gif *.jpg
	${INSTALL_DATA} ${WRKSRC}/docs/ctf/${f} ${DOCSDIR}/ctf
.endfor
.endif
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
