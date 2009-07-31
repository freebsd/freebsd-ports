# New ports collection makefile for:	ecore-evas
# Date created:				17 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evas
PORTVERSION=	0.9.9.042
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (evas module)

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
USE_EFL=	ecore evas
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_evas
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ARGS=	--disable-ecore-con \
		--disable-ecore-config \
		--disable-ecore-desktop \
		--disable-ecore-directfb \
		--enable-ecore-evas \
		--disable-ecore-file \
		--disable-ecore-ipc \
		--disable-ecore-job \
		--disable-ecore-sdl \
		--disable-ecore-txt \
		--disable-ecore-x \
		--disable-ecore-imf \
		--disable-ecore-imf_evas

OPTIONS=	X11	"Enable Evas X11 support"	on \
		GL	"Enable Evas GL support"	on \
		XRENDER	"Enable Evas Xrender support"	on \
		BUFFER	"Enable Evas Buffer support"	on \
		SDL	"Enable Evas SDL support"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GL)
CONFIGURE_ARGS+=	--enable-ecore-evas-gl
USE_EFL_EVAS_ENGINES+=	opengl
USE_X=			yes
.else
CONFIGURE_ARGS+=	--disable-ecore-evas-gl
.endif

.if !defined(WITHOUT_XRENDER)
CONFIGURE_ARGS+=	--enable-ecore-evas-xrender
USE_EFL_EVAS_ENGINES+=	xrender
USE_X=			yes
.else
CONFIGURE_ARGS+=	--disable-ecore-evas-xrender
.endif

.if !defined(WITHOUT_X11) || defined(USE_X)
CONFIGURE_ARGS+=	--enable-ecore-x
USE_EFL_ECORE+=		x11
USE_EFL_EVAS_ENGINES+=	x11
.else
CONFIGURE_ARGS+=	--disable-ecore-x
.endif

.if !defined(WITHOUT_BUFFER)
CONFIGURE_ARGS+=	--enable-ecore-evas-buffer
USE_EFL_EVAS_ENGINES+=	buffer
.else
CONFIGURE_ARGS+=	--disable-ecore-evas-buffer
.endif

.if !defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--enable-ecore-evas-sdl
USE_EFL_EVAS_ENGINES+=	sdl
USE_EFL_ECORE+=	sdl
.else
CONFIGURE_ARGS+=	--disable-ecore-evas-sdl
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_x/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_sdl/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_x/libecore_x\.la,-lecore_x,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_sdl/libecore_sdl\.la,-lecore_sdl,'\
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-evas.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
