# New ports collection makefile for:	quake2
# Date created:				20.01.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	quake2forge
PORTVERSION=	0.3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.quakeforge.net/quake2forge/ \
		http://www.galgenberg.net/~q/
DISTNAME=	quake2-${PORTVERSION}

MAINTAINER=	q@galgenberg.net
COMMENT=	First Person Shooter with many addons available

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_AUTOCONF_VER=259
USE_XLIB=	yes
USE_REINPLACE=	yes
WANT_SDL=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--program-transform-name='s/^quake2$$/q2f/'
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if ${HAVE_SDL:Msdl}!=""
WITH_SDL=	yes
.endif

.if exists(${LOCALBASE}/lib/libvga.so.1)
WITH_SVGALIB=	yes
.endif

.if exists(${LOCALBASE}/lib/libao.so.3)
WITH_LIBAO=	yes
.endif

.if !defined (WITHOUT_LIBAO) && defined(WITH_LIBAO)
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao
CONFIGURE_ARGS+=--with-ao=${LOCALBASE}
PLIST_SUB+=	AO:=""
.else
CONFIGURE_ARGS+=--without-ao
PLIST_SUB+=	AO:="@comment "
.endif

.if !defined (WITHOUT_SVGALIB) && defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--with-svgalib=${LOCALBASE}
PLIST_SUB+=	SVGA:=""
.else
CONFIGURE_ARGS+=--with-svgalib=no
PLIST_SUB+=	SVGA:="@comment "
.endif

.if !defined(WITHOUT_GL)
CONFIGURE_ARGS+=--with-opengl=${X11BASE}
PLIST_SUB+=	GL:=""
.else
CONFIGURE_ARGS+=--with-opengl=no
PLIST_SUB+=	GL:="@comment "
.endif

.if !defined(WITHOUT_SDL) && defined(WITH_SDL)
USE_SDL=	yes
CONFIGURE_ARGS+=--with-sdl=${LOCALBASE}
.if !defined(WITHOUT_GL)
PLIST_SUB+=	SDLGL:=""
.else
PLIST_SUB+=	SDLGL:="@comment "
.endif
PLIST_SUB+=	SDL:=""
.else
CONFIGURE_ARGS+=--disable-sdl --disable-sdltest
PLIST_SUB+=	SDL:="@comment "
PLIST_SUB+=	SDLGL:="@comment "
.endif

pre-everything::
.if !defined(WITH_LIBAO)
	@${ECHO_MSG} "Define WITH_LIBAO to use libao"
.endif
.if !defined(WITH_SVGALIB)
	@${ECHO_MSG} "Define WITH_SVGALIB to use svgalib"
.endif
.if !defined(WITH_SDL)
	@${ECHO_MSG} "Define WITH_SDL to use SDL"
.endif
.if !defined(WITHOUT_GL)
	@${ECHO_MSG} "Define WITHOUT_GL to disable GL"
.endif

.if ( ${OSVERSION} < 500000 )
post-patch:
	@${REINPLACE_CMD} -e 's/%zu/%u/g' ${WRKSRC}/src/main.c
.endif

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/quake2/ctf
	${INSTALL_MAN} ${WRKSRC}/docs/README.* ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/quake2
	${INSTALL_MAN} ${WRKSRC}/docs/ctf/*.html ${WRKSRC}/docs/ctf/*.gif \
		${WRKSRC}/docs/ctf/*.jpg ${PREFIX}/share/doc/quake2/ctf
.endif

post-install:
	@${SED} -e 's#$${PREFIX}#${PREFIX}#g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
