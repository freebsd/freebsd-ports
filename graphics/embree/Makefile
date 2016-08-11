# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	embree
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Collection of high-performance ray tracing kernels

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	heavy use of SSE instructions

BROKEN_FreeBSD_9=	does not build (insufficient C++11 support)

USE_GITHUB=	yes

USES=		cmake
USE_GL=		glut
USE_XORG=	xmu
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DRTCORE_TASKING_SYSTEM:STRING=INTERNAL \
		-DENABLE_ISPC_SUPPORT:BOOL=OFF

CXXFLAGS+=	-msse2					# required on i386

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}2
PLIST_SUB+=	VERSION=${DISTVERSION}

OPTIONS_DEFINE=	IMAGE_MAGICK JPEG OPENEXR PNG
IMAGE_MAGICK_DESC=	BMP, GIF, PNG, TGA, TIFF image formats support

IMAGE_MAGICK_LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick
IMAGE_MAGICK_CMAKE_ON=	-DUSE_IMAGE_MAGICK:BOOL=ON

JPEG_USES=		jpeg
JPEG_CMAKE_OFF=		-DUSE_LIBJPEG:BOOL=OFF

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR
OPENEXR_CMAKE_OFF=	-DUSE_OPENEXR:BOOL=OFF

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_OFF=		-DUSE_LIBPNG:BOOL=OFF

post-patch:
	@${REINPLACE_CMD} -e 's,MAP_HUGETLB,MAP_ALIGNED_SUPER,' \
		${WRKSRC}/common/sys/alloc.cpp
	@${REINPLACE_CMD} -e '/__aligned/s,^,//,' \
		${WRKSRC}/common/sys/platform.h
	@${REINPLACE_CMD} -e 's,MAP_POPULATE,MAP_PREFAULT_READ,' \
		${WRKSRC}/tests/benchmark.cpp
	@${REINPLACE_CMD} -e '/encodeRGB8_to_JPEG/s,size_t \*,unsigned \
		long *,' ${WRKSRC}/tutorials/common/image/image.h \
		${WRKSRC}/tutorials/common/image/jpeg.cpp
	@${REINPLACE_CMD} -e 's,__forceinline,inline __attribute__((always_inline)),' \
		${WRKSRC}/include/embree2/rtcore_ray.h

.include <bsd.port.mk>
