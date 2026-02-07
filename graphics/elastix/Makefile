PORTNAME=	elastix
DISTVERSION=	5.1.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Image registration toolbox
WWW=		https://elastix.lumc.nl/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdouble-conversion.so:devel/double-conversion \
		libgdcmCommon.so:devel/gdcm \
		libhdf5.so:science/hdf5 \
		libITKCommon-${ITK_VER}.so:science/InsightToolkit \
		libvnl.so:misc/vxl

USES=		cmake:testing compiler:c++14-lang eigen:3
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SuperElastix

CMAKE_ON=	ELASTIX_USE_EIGEN

CXXFLAGS+=	-I${LOCALBASE}/include/double-conversion

.include <../../science/InsightToolkit/Makefile.version>
.include <bsd.port.mk>
