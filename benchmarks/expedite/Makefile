# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	expedite
PORTVERSION=	1.7.9
CATEGORIES=	benchmarks enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Expedite is a benchmark suite for Evas

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_EFL=	evas
USE_EFL_EVAS_ENGINES=	buffer
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	OPENGL SDL X11
OPTIONS_DEFAULT=OPENGL X11
OPENGL_DESC=	Enable OpenGL evas engine
SDL_DESC=	Enable SDL evas engine
X11_DESC=	Enable X11 evas engine

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENGL}
USE_EFL_EVAS_ENGINES+=	opengl
CONFIGURE_ARGS+=	--enable-opengl-x11
.else
CONFIGURE_ARGS+=	--disable-opengl-x11
.endif

.if ${PORT_OPTIONS:MSDL}
USE_EFL_EVAS_ENGINES+=	sdl
CONFIGURE_ARGS+=	--enable-software-sdl
.else
CONFIGURE_ARGS+=	--disable-software-sdl
.endif

.if ${PORT_OPTIONS:MX11}
USE_EFL_EVAS_ENGINES+=	x11
CONFIGURE_ARGS+=	--enable-software-x11 --enable-xrender-x11
.else
CONFIGURE_ARGS+=	--disable-software-x11 --disable-xrender-x11
.endif

.include <bsd.port.mk>
