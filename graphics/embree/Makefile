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

LIB_DEPENDS=	libMagick++-6.so:${PORTSDIR}/graphics/ImageMagick \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR

BROKEN_FreeBSD_9=	does not build (insufficient C++11 support)

USE_GITHUB=	yes

USES=		cmake compiler:c++11-lang
USE_GL=		glut
USE_XORG=	xmu
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DRTCORE_TASKING_SYSTEM:STRING=INTERNAL \
		-DENABLE_ISPC_SUPPORT:BOOL=OFF \
		-DCOMPILER:STRING=${CHOSEN_COMPILER_TYPE:tu}

PLIST_SUB+=	VERSION=${DISTVERSION}

post-patch:
# MAP_NORESERVE was never implemented in FreeBSD and retired in r273250
	@${REINPLACE_CMD} -e 's,MAP_NORESERVE,0,' \
		${WRKSRC}/common/sys/alloc.cpp
	@${REINPLACE_CMD} -e 's,_blsr_u64,_&,' \
		${WRKSRC}/common/sys/intrinsics.h
	@${REINPLACE_CMD} -e 's,__UNIX__) &&.*,__LINUX__),' \
		${WRKSRC}/tests/benchmark.cpp
	@${REINPLACE_CMD} -e '/share\/doc/,+2 { \
		s,share/doc/embree-[^)]*,${DOCSDIR_REL}, ; \
		s,bin/,, ; } ' ${WRKSRC}/common/cmake/package.cmake
# Do not force particular compiler binaries (obey the framework)
	@${REINPLACE_CMD} -e '/_COMPILER/s,^,#,' \
		${WRKSRC}/common/cmake/clang.cmake \
		${WRKSRC}/common/cmake/gcc.cmake

post-install:
	${LN} -sf libembree.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libembree.so

.include <bsd.port.mk>
