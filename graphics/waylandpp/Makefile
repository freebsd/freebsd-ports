# $FreeBSD$

PORTNAME=	waylandpp
DISTVERSION=	0.2.4
CATEGORIES=	graphics

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Wayland C++ bindings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-egl.so:graphics/wayland

USES=		cmake compiler:c++11-lang gl pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	NilsBrause
USE_GL=		egl
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_DOCUMENTATION BUILD_EXAMPLES

.include <bsd.port.mk>
