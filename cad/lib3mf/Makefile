PORTNAME=	lib3mf
DISTVERSIONPREFIX=v
DISTVERSION=	2.4.1
#PORTREVISION=	1
CATEGORIES=	cad
#PKGNAMESUFFIX=  -devel

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Implementation of the 3D Manufacturing Format file standard
WWW=		http://3mf.io/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

#CONFLICTS_INSTALL=      lib3mf-devel #

LIB_DEPENDS=	libgtest.so:devel/googletest \
		libzip.so:archivers/libzip

USES=		compiler:c++20-lang cmake pkgconfig python
USE_GITHUB=	yes
GH_ACCOUNT=	3MFConsortium
GH_PROJECT=	lib3mf

CMAKE_ARGS+=	-DUSE_INCLUDED_ZLIB=OFF \
		-DUSE_INCLUDED_LIBZIP=OFF \
		-DUSE_INCLUDED_SSL=OFF \
		-DLIB3MF_TESTS=OFF

CXXFLAGS+=	-I${WRKSRC}/Include -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.include <bsd.port.mk>
