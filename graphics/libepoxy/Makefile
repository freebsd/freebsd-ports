PORTNAME=	libepoxy
DISTVERSION=	1.5.9
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/anholt/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library to handle OpenGL function pointer management
WWW=		https://github.com/anholt/libepoxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl localbase meson pkgconfig python:build shebangfix tar:xz
USE_GL=		glesv2 egl
USE_LDCONFIG=	yes
SHEBANG_FILES=	src/gen_dispatch.py

OPTIONS_DEFINE=		TEST X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=		yes

OPTIONS_DEFINE_aarch64=		EGL
OPTIONS_DEFAULT_aarch64=	EGL
OPTIONS_DEFINE_aarch64c=	EGL
OPTIONS_DEFAULT_aarch64c=	EGL

TEST_MESON_TRUE=	tests

X11_USES=		xorg
X11_USE=		GL=gl XORG=x11
X11_MESON_YES=		glx
X11_MESON_TRUE=		x11

EGL_DESC=		EGL support
EGL_MESON_YES=		egl

.include <bsd.port.mk>
