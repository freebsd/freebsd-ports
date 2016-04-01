# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	embree
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Collection of high-performance ray tracing kernels

LICENSE=	APACHE20

LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick \
		libIlmImf.so:graphics/OpenEXR

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	heavy use of SSE instructions

BROKEN_FreeBSD_9=	does not build (insufficient C++11 support)

USE_GITHUB=	yes

USES=		cmake compiler:c++11-lang
USE_GL=		glut
USE_XORG=	xmu
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DRTCORE_TASKING_SYSTEM:STRING=INTERNAL \
		-DENABLE_ISPC_SUPPORT:BOOL=OFF \
		-DCOMPILER:STRING=${CHOSEN_COMPILER_TYPE:tu}

CXXFLAGS+=	-msse2					# required on i386

PLIST_SUB+=	VERSION=${DISTVERSION}

post-patch:
# MAP_NORESERVE was never implemented in FreeBSD and retired in r273250
	@${REINPLACE_CMD} -e 's,MAP_NORESERVE,0,' \
		${WRKSRC}/common/sys/alloc.cpp
	@${REINPLACE_CMD} -e '/__aligned/s,^,//,' \
		${WRKSRC}/common/sys/platform.h
	@${REINPLACE_CMD} -e 's,__UNIX__) &&.*,__LINUX__),' \
		${WRKSRC}/tests/benchmark.cpp
	@${REINPLACE_CMD} -e '/share\/doc/,+2 { \
		s,share/doc/embree-[^)]*,${DOCSDIR_REL}, ; \
		s,bin/,, ; } ' ${WRKSRC}/common/cmake/package.cmake
	@${REINPLACE_CMD} -e '/encodeRGB8_to_JPEG/s,size_t \*,unsigned \
		long *,' ${WRKSRC}/tutorials/common/image/image.h \
		${WRKSRC}/tutorials/common/image/jpeg.cpp

post-install:
	${LN} -sf libembree.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libembree.so

.include <bsd.port.mk>
