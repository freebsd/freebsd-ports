PORTNAME=	ect
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.5
CATEGORIES=	graphics archivers

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Efficient Compression Tool, a fast and effective file optimizer
WWW=		https://github.com/fhanau/Efficient-Compression-Tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/License.txt

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	32-bit x86 is not supported upstream

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	fhanau
GH_PROJECT=	Efficient-Compression-Tool
GH_TUPLE=	glennrp:libpng:f135775ad4e5d4408d2e12ffcc71bb36e6b48551:libpng/src/libpng \
		fhanau:mozjpeg:182457e3e26e1e078d5dbd09137cf04865be2e49:mozjpeg/src/mozjpeg

CMAKE_SOURCE_PATH=	${WRKSRC}/src

PLIST_FILES=	bin/ect

OPTIONS_DEFINE_amd64=	SIMD

SIMD_DESC=		Use SSSE3, SSE4.2 and PCLMUL (requires Nehalem or newer CPU)
SIMD_CMAKE_BOOL=	ECT_X86_SIMD

.include <bsd.port.mk>
