# $FreeBSD$

PORTNAME=	libgltf
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	LODEV

MAINTAINER=	office@FreeBSD.org
COMMENT=	C++ Library for rendering OpenGL models stored in glTF format

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/ptr_container/ptr_map.hpp:devel/boost-libs \
		${LOCALBASE}/include/glm/glm.hpp:math/glm

USES=		compiler:c++0x libtool pathfix pkgconfig tar:bzip2
USE_GL=		glew
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-werror
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
