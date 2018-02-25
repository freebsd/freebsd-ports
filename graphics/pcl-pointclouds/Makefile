# $FreeBSD$

PORTNAME=	pcl
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	graphics math
PKGNAMESUFFIX=	-pointclouds

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Point Cloud Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libflann_cpp.so:math/flann \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libvtkCommonCore-6.2.so:math/vtk6

USES=		cmake:outsource eigen:3,build jpeg python
USE_GITHUB=	yes
GH_ACCOUNT=	PointCloudLibrary
USE_GL=		gl glu
USE_XORG=	x11 xext xt ice sm
USE_LDCONFIG=	yes

PLIST_SUB=	SHL3=${DISTVERSION} SHL2=${DISTVERSION:R}

DATADIR=	${PREFIX}/share/${PORTNAME}-${DISTVERSION:R}  # match the directory where the project installs .cmake files

post-patch:  # 10 doesn't have std::sqrt, switching to ::sqrt from math.h
	@${GREP} -rl std::sqrt ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e 's|::std::sqrt|::sqrt|g ; s|std::sqrt|::sqrt|g'

.include <bsd.port.mk>
