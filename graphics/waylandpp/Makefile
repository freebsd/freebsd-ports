PORTNAME=	waylandpp
DISTVERSION=	1.0.1
CATEGORIES=	graphics

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Wayland C++ bindings
WWW=		https://github.com/NilsBrause/waylandpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpugixml.so:textproc/pugixml \
		libwayland-egl.so:graphics/wayland

USES=		cmake compiler:c++11-lang gl localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	NilsBrause
USE_GL=		egl
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_DOCUMENTATION BUILD_EXAMPLES
PLIST_SUB=	SOVERSION=${DISTVERSION}

.include <bsd.port.mk>
