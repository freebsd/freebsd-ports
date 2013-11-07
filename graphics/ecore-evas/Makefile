# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evas
PORTVERSION=	1.7.9
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	ecore-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (evas module)

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_EFL=	evas ecore libtool_hack
USE_EFL_ECORE=	input input_evas
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_evas
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "../../devel/ecore-main/Makefile.inc"

CONFIGURE_ARGS+=	--enable-ecore-evas \
			--enable-ecore-input \
			--enable-ecore-input_evas

OPTIONS_DEFINE=	BUFFER OPENGL SDL X11
OPTIONS_DEFAULT=BUFFER OPENGL X11
BUFFER_DESC=	Enable Buffer evas engine
OPENGL_DESC=	Enable OpenGL evas engine
SDL_DESC=	Enable SDL evas engine
X11_DESC=	Enable X11 evas engine

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBUFFER}
CONFIGURE_ARGS+=	--enable-ecore-evas-software-buffer
USE_EFL_EVAS_ENGINES+=	buffer
.else
CONFIGURE_ARGS+=	--disable-ecore-evas-software-buffer
.endif

.if ${PORT_OPTIONS:MOPENGL}
CONFIGURE_ARGS+=	--enable-ecore-evas-opengl-x11
USE_EFL_EVAS_ENGINES+=	opengl
WITH_X=			yes
.else
CONFIGURE_ARGS+=	--disable-ecore-evas-opengl-x11
.endif

.if ${PORT_OPTIONS:MSDL}
CONFIGURE_ARGS+=	--enable-ecore-sdl
USE_EFL_EVAS_ENGINES+=	sdl
USE_EFL_ECORE+=	sdl
.else
CONFIGURE_ARGS+=	--disable-ecore-sdl
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--enable-ecore-x
USE_EFL_ECORE+=		x11
USE_EFL_EVAS_ENGINES+=	x11
.else
CONFIGURE_ARGS+=	--disable-ecore-x
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
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
