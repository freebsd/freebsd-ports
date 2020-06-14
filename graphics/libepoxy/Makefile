# $FreeBSD$

PORTNAME=	libepoxy
PORTVERSION=	1.5.4
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library to handle OpenGL function pointer management

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl localbase meson pkgconfig python:3.3+,build
USE_GITHUB=	yes
GH_ACCOUNT=	anholt
USE_GL=		glesv2 egl
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=		yes

X11_USES=		xorg
X11_USE=		GL=gl XORG=x11
X11_MESON_YES=		glx
X11_MESON_TRUE=		x11
X11_CFLAGS_OFF=		-DEGL_NO_X11

.include <bsd.port.mk>
