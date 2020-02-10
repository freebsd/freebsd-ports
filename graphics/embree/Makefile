# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	embree
PORTVERSION=	3.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Collection of high-performance ray tracing kernels

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	heavy use of SSE instructions

USES=		cmake pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes

CMAKE_ARGS=	-DEMBREE_TASKING_SYSTEM:STRING=INTERNAL \
		-DCMAKE_INSTALL_DOCDIR:STRING=${DOCSDIR}

PLIST_SUB+=	VERSION=${DISTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES ISPC
OPTIONS_SUB=	yes

ISPC_DESC=		ISPC applications support
ISPC_BUILD_DEPENDS=	ispc:devel/ispc
ISPC_CMAKE_OFF=		-DEMBREE_ISPC_SUPPORT:BOOL=OFF

EXAMPLES_LIB_DEPENDS=	libglfw.so:graphics/glfw \
			libpng.so:graphics/png
EXAMPLES_USES=		gl jpeg xorg
EXAMPLES_USE=		GL=gl,glu,glut XORG=x11,xau,xcb,xdmcp
EXAMPLES_CMAKE_OFF=	-DEMBREE_TUTORIALS:BOOL=OFF

.include <bsd.port.pre.mk>

# Disable parts that use _mm_cvtsi128_si64() which is not defined on i386
.if ${ARCH} == i386
CMAKE_ARGS+=	-DEMBREE_ISA_AVX512SKX:BOOL=OFF
.endif

post-patch:
	@${REINPLACE_CMD} -e \
	    '/SET(CMAKE_INSTALL_BINDIR/s,\$$.*),${EXAMPLESDIR}),' \
		${WRKSRC}/common/cmake/package.cmake
	@${REINPLACE_CMD} -e 's,Win32,${OPSYS},gi' \
		${WRKSRC}/common/simd/vint4_sse2.h
	@${REINPLACE_CMD} -e 's,#else,#elif defined(MAP_HUGETLB),' \
		${WRKSRC}/common/sys/alloc.cpp
	@${ECHO_CMD} > ${WRKSRC}/tutorials/common/common.isph

.include <bsd.port.post.mk>
