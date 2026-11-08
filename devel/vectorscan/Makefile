PORTNAME=	vectorscan
DISTVERSIONPREFIX=	vectorscan/
DISTVERSION=	5.4.13
CATEGORIES=	devel textproc

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Portable fork of high-performance multiple regex matching library
WWW=		https://github.com/VectorCamp/vectorscan

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64le

BUILD_DEPENDS=	ragel:devel/ragel \
		${LOCALBASE}/include/boost/graph/adjacency_list.hpp:devel/boost-libs \
		${LOCALBASE}/include/simde/x86/sse4.2.h:devel/simde

USES=		cmake compiler:c++17-lang localbase pathfix python:build
USE_GITHUB=	yes
GH_ACCOUNT=	VectorCamp

CMAKE_ARGS+=	-DBOOST_ROOT=${LOCALBASE}

CFLAGS+=	-fPIC

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS SHARED
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS SHARED
OPTIONS_DEFAULT_amd64=	FAT_RUNTIME
OPTIONS_RADIO=		ISA
OPTIONS_RADIO_ISA=	NATIVE FAT_RUNTIME
OPTIONS_RADIO_ISA_amd64=	AVX2 AVX512 AVX512VBMI
OPTIONS_RADIO_ISA_aarch64=	SVE SVE2 SVE2_BITPERM
OPTIONS_SUB=		yes

AVX2_DESC=		Enable AVX2 instructions for fixed-ISA builds
AVX512_DESC=		Enable AVX512 instructions for fixed-ISA builds
AVX512VBMI_DESC=	Enable AVX512VBMI instructions for fixed-ISA builds
FAT_RUNTIME_DESC=	Build for multiple microarchitectures with runtime ISA dispatch
NATIVE_DESC=		Build with native CPU tunes
SHARED_DESC=		Build shared library
SVE_DESC=		Enable Arm SVE instructions
SVE2_DESC=		Enable Arm SVE2 instructions
SVE2_BITPERM_DESC=	Enable Arm SVE2 bit permutation instructions

AVX2_CMAKE_BOOL=	BUILD_AVX2
AVX512_CMAKE_ON=	-DBUILD_AVX2:BOOL=ON -DBUILD_AVX512:BOOL=ON
AVX512VBMI_CMAKE_ON=	-DBUILD_AVX2:BOOL=ON -DBUILD_AVX512:BOOL=ON \
			-DBUILD_AVX512VBMI:BOOL=ON
FAT_RUNTIME_CMAKE_BOOL=		FAT_RUNTIME
NATIVE_CMAKE_BOOL=		USE_CPU_NATIVE
OPTIMIZED_CFLAGS_CFLAGS=	-O3
OPTIMIZED_CFLAGS_CXXFLAGS=	-O3
SHARED_CMAKE_ON=	-DBUILD_SHARED_LIBS:BOOL=ON -DBUILD_STATIC_LIBS:BOOL=ON
SHARED_CMAKE_OFF=	-DBUILD_STATIC_LIBS:BOOL=ON
SHARED_VARS=		PLIST_SUB+="SOVERSION=${PORTVERSION}" \
			PLIST_SUB+="SOSHORTVERSION=${PORTVERSION:R:R}"
SVE_CMAKE_BOOL=		BUILD_SVE
SVE2_CMAKE_ON=		-DBUILD_SVE:BOOL=ON -DBUILD_SVE2:BOOL=ON
SVE2_BITPERM_CMAKE_ON=	-DBUILD_SVE:BOOL=ON -DBUILD_SVE2:BOOL=ON \
			-DBUILD_SVE2_BITPERM:BOOL=ON

.include <bsd.port.options.mk>

# On FreeBSD 14, base nm is elftoolchain which doesn't support -f posix.
# Use base llvm-nm instead (build_wrapper.sh needs this for FAT_RUNTIME).
.if ${OSVERSION} < 1500000
BINARY_ALIAS+=	nm=llvm-nm
.endif

post-patch:
	${RM} ${WRKSRC}/tools/CMakeLists.txt

do-test:
	cd ${BUILD_WRKSRC} && ${MAKE_CMD} unit

.include <bsd.port.mk>
