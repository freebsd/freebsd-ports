PORTNAME=	libGLU
PORTVERSION=	9.0.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/glu/ \
		https://mesa.freedesktop.org/archive/glu/
DISTNAME=	glu-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL utility library
WWW=		https://gitlab.freedesktop.org/mesa/glu

USES=		gl meson pkgconfig tar:xz

USE_GL=		opengl
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddefault_library=shared

.include <bsd.port.mk>
