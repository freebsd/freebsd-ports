# New ports collection makefile for:	ecore-evas
# Date created:				17 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evas
DISTVERSION=	1.0.1
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-05-25/base/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (evas module)

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	evas ecore libtool_hack
USE_EFL_ECORE=	input input_evas sdl
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_evas
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "../../devel/ecore-main/Makefile.inc"

CONFIGURE_ARGS+=	--enable-ecore-evas \
			--enable-ecore-input \
			--enable-ecore-input_evas

OPTIONS=	X11	"Enable Evas X11 support"	on \
		GL	"Enable Evas GL support"	on \
		XRENDER	"Enable Evas Xrender support"	on \
		BUFFER	"Enable Evas Buffer support"	on \
		SDL	"Enable Evas SDL support"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GL)
CONFIGURE_ARGS+=	--enable-ecore-evas-opengl-x11
USE_EFL_EVAS_ENGINES+=	opengl
WITH_X=			yes
.else
CONFIGURE_ARGS+=	--disable-ecore-evas-opengl-x11
.endif

.if !defined(WITHOUT_XRENDER)
CONFIGURE_ARGS+=	--enable-ecore-evas-xrender-x11
USE_EFL_EVAS_ENGINES+=	xrender
WITH_X=			yes
.else
CONFIGURE_ARGS+=	--disable-ecore-evas-xrender-x11
.endif

.if !defined(WITHOUT_X11) || defined(WITH_X)
CONFIGURE_ARGS+=	--enable-ecore-x
USE_EFL_ECORE+=		x11
USE_EFL_EVAS_ENGINES+=	x11
.else
CONFIGURE_ARGS+=	--disable-ecore-x
.endif

.if !defined(WITHOUT_BUFFER)
CONFIGURE_ARGS+=	--enable-ecore-evas-software-buffer
USE_EFL_EVAS_ENGINES+=	buffer
.else
CONFIGURE_ARGS+=	--disable-ecore-evas-software-buffer
.endif

.if !defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--enable-ecore-evas-software-sdl --enable-ecore-sdl
USE_EFL_EVAS_ENGINES+=	sdl
USE_EFL_ECORE+=	sdl
.else
CONFIGURE_ARGS+=	--disable-ecore-evas-software-sdl --enable-ecore-sdl
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_x/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_sdl/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_input/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_input_evas/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_x/libecore_x\.la,-lecore_x,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_sdl/libecore_sdl\.la,-lecore_sdl,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_input/libecore_input\.la,-lecore_input,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_input_evas/libecore_input_evas\.la,-lecore_input_evas,'\
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-evas.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
