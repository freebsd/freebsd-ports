# New ports collection makefile for:	quake2
# Date created:				20.01.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	quake2forge
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	quake
DISTNAME=	quake2-${PORTVERSION}

MAINTAINER=	q@uni.de
COMMENT=	First Person Shooter with many addons available

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/lib/quake2 ${PREFIX}/lib/quake2/baseq2 ${PREFIX}/lib/quake2/ctf

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--enable-static=no --program-transform-name='s/^quake2$$/q2f/'
CONFIGURE_TARGET=

.if exists(${LOCALBASE}/lib/libSDL-1.1.so.5)
WITH_SDL=	yes
.endif

.if exists(${LOCALBASE}/lib/libvga.so.1)
WITH_SVGALIB=	yes
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
.if !defined(WITH_SVGALIB)
	@${ECHO_MSG} "Define WITH_SVGALIB to use svgalib"
.endif
.if !defined(WITH_SDL)
	@${ECHO_MSG} "Define WITH_SDL to use SDL"
.endif
.if !defined(WITHOUT_GL)
	@${ECHO_MSG} "Define WITHOUT_GL to disable GL"
.endif

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/quake2
	${MKDIR} ${PREFIX}/share/doc/quake2/ctf
	${INSTALL_MAN} ${WRKSRC}/docs/README.* ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/quake2
	${INSTALL_MAN} ${WRKSRC}/docs/ctf/* ${PREFIX}/share/doc/quake2/ctf
.endif

post-install:
	@${SED} -e 's#$${PREFIX}#${PREFIX}#g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
