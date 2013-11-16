# $FreeBSD$

PORTNAME=	opencollada
PORTVERSION=	1.2.2.20131105
CATEGORIES=	graphics devel

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Library for reading and writing COLLADA files

LICENSE=	MIT

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	OpenCOLLADA
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	bd15211

WRKSRC=		${WRKDIR}/KhronosGroup-OpenCOLLADA-${GH_COMMIT}

USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USES=		cmake:outsource compiler iconv pkgconfig
CFLAGS+=	-I/${LOCALBASE}/include
CMAKE_ARGS+=	-DUSE_SHARED:BOOL=ON -DUSE_STATIC:BOOL=OFF

post-patch:
	@${REINPLACE_CMD} -e 's|$${OPENCOLLADA_INST_LIBRARY}/cmake|${PREFIX}/share/cmake/Modules|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
