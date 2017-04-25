# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	expedite
PORTVERSION=	1.7.10
PORTREVISION=	2
CATEGORIES=	benchmarks enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Expedite is a benchmark suite for Evas

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libefl.so:devel/efl

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		pkgconfig python:run shebangfix tar:bzip2
USE_LDCONFIG=	yes
SHEBANG_FILES=	src/bin/expedite-cmp

OPTIONS_DEFINE=	OPENGL SDL X11
OPTIONS_DEFAULT=OPENGL X11
OPENGL_DESC=	Enable OpenGL evas engine
SDL_DESC=	Enable SDL evas engine
X11_DESC=	Enable X11 evas engine

OPENGL_CONFIGURE_ENABLE=	opengl-x11
SDL_CONFIGURE_ENABLE=		software-sdl
X11_CONFIGURE_ENABLE=		software-x11 xrender-x11

.include <bsd.port.mk>
