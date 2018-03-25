# $FreeBSD$

PORTNAME=	waylandpp
DISTVERSION=	0.2.2
CATEGORIES=	graphics

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Wayland C++ bindings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	NilsBrause
USE_GL=		egl

CMAKE_OFF=	BUILD_DOCUMENTATION BUILD_EXAMPLES

OPTIONS_DEFINE=	WAYLAND

WAYLAND_DESC=	Requires graphics/mesa-libs with WAYLAND on

WAYLAND_IGNORE_OFF=	Cannot be built without Wayland support
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libwayland-egl.so:graphics/mesa-libs

.include <bsd.port.mk>
