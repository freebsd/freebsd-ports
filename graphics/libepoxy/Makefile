# $FreeBSD$

PORTNAME=	libepoxy
PORTVERSION=	1.4.3
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/anholt/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library to handle OpenGL function pointer management

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase meson pkgconfig python:3.3+,build tar:xz
USE_XORG=	x11
USE_GL=		gl glesv2
USE_LDCONFIG=	yes

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	EGL
OPTIONS_DEFAULT=EGL

OPTIONS_EXCLUDE_sparc64=	EGL
OPTIONS_EXCLUDE_mips=	EGL

EGL_DESC=	Build EGL support
EGL_USE=	GL=egl
EGL_MESON_YES=	enable-egl

.include <bsd.port.mk>
