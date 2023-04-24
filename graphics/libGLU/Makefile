PORTNAME=	libGLU
PORTVERSION=	9.0.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/glu/ \
		https://mesa.freedesktop.org/archive/glu/
DISTNAME=	glu-${PORTVERSION}

PATCH_SITES=	https://gitlab.freedesktop.org/mesa/glu/-/commit/
PATCHFILES+=	b6c308172993.patch:-p1 #https://gitlab.freedesktop.org/mesa/glu/-/merge_requests/10

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL utility library
WWW=		https://gitlab.freedesktop.org/mesa/glu

USES=		gl meson pkgconfig tar:xz

USE_GL=		opengl
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddefault_library=shared

.include <bsd.port.mk>
