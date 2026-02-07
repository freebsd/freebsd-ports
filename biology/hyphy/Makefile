PORTNAME=	hyphy
DISTVERSION=	2.5.90
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Hypothesis testing using Phylogenies
WWW=		https://www.hyphy.org/ \
		https://github.com/veg/hyphy/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc powerpc64 powerpc64le

LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	bash:shells/bash

USES=		cmake:insource,testing localbase:ldflags # tests fail in outsource build, see https://github.com/veg/hyphy/issues/1528

USE_GITHUB=	yes
GH_ACCOUNT=	veg

OPTIONS_DEFINE=		AVX FMA3 NEON SSE4 TARGET_NATIVE
AVX_DESC=		Support for AVX (Advanced Vector Extensions) instructions
FMA3_DESC=		Support for FMA3 (Fused Multiply-Add) instructions on x86
NEON_DESC=		Support for NEON SIMD instructions on ARM
SSE4_DESC=		Support for SSE4 (Streaming SIMD Extensions) instructions
TARGET_NATIVE_DESC=	Enable CPU-specific optimizations for the build machine

AVX_CMAKE_BOOL_OFF=		NOAVX
FMA3_CMAKE_BOOL_OFF=		NOFMA3
NEON_CMAKE_BOOL_OFF=		NONEON
SSE4_CMAKE_BOOL_OFF=		NOSSE4
TARGET_NATIVE_CMAKE_BOOL=	TARGET_NATIVE

.include <bsd.port.mk>
