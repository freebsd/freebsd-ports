# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	embree
PORTVERSION=	2.17.3
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Collection of high-performance ray tracing kernels

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	heavy use of SSE instructions

USE_GITHUB=	yes

USES=		cmake compiler:env
USE_GL=		gl glu glut
USE_XORG=	xi xmu
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DEMBREE_TASKING_SYSTEM:STRING=INTERNAL

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}2
PLIST_SUB+=	VERSION=${DISTVERSION}

OPTIONS_DEFINE=	IMAGEMAGICK ISPC JPEG PNG
OPTIONS_DEFAULT=	ISPC
OPTIONS_SUB=	yes

IMAGEMAGICK_DESC=	BMP, GIF, PNG, TGA, TIFF image formats support
IMAGEMAGICK_LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick
IMAGEMAGICK_CMAKE_ON=	-DEMBREE_TUTORIALS_IMAGE_MAGICK:BOOL=ON

ISPC_DESC=		ISPC applications support
ISPC_BUILD_DEPENDS=	ispc:devel/ispc
ISPC_CMAKE_OFF=		-DEMBREE_ISPC_SUPPORT:BOOL=OFF

JPEG_USES=		jpeg
JPEG_CMAKE_OFF=		-DEMBREE_TUTORIALS_LIBJPEG:BOOL=OFF

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_OFF=		-DEMBREE_TUTORIALS_LIBPNG:BOOL=OFF

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,#else,#elif defined(MAP_HUGETLB),' \
		${WRKSRC}/common/sys/alloc.cpp
# Old versions of Clang (e.g. on FreeBSD 10.x) do not support `-z' options
.if ${COMPILER_VERSION} < 35
	@${REINPLACE_CMD} -e '/ -z /d' ${WRKSRC}/common/cmake/clang.cmake
.endif

.include <bsd.port.post.mk>
