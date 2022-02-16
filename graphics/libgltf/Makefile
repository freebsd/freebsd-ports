PORTNAME=	libgltf
PORTVERSION=	0.1.0
CATEGORIES=	graphics devel
MASTER_SITES=	LODEV

MAINTAINER=	office@FreeBSD.org
COMMENT=	C++ Library for rendering OpenGL models stored in glTF format

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/ptr_container/ptr_map.hpp:devel/boost-libs \
		${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy

USES=		compiler:c++0x gl libtool localbase pathfix pkgconfig
USE_GL=		glew
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-werror
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
