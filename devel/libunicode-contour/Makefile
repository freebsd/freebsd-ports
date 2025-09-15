PORTNAME=	libunicode
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMESUFFIX=	-contour

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Modern C++20 Unicode library
WWW=		https://github.com/contour-terminal/libunicode

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/pkgconfig/catch2-with-main.pc:devel/catch2 \
		UCD>=16.0.0,1:textproc/UCD

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	contour-terminal

USE_LDCONFIG=	${PREFIX}/lib/contour

CMAKE_ARGS=	-DLIBUNICODE_UCD_DIR:STRING=${LOCALBASE}/share/unicode/ucd \
		${CMAKE_ARGS_${ARCH}}
CMAKE_ARGS_armv7=	-DLIBUNICODE_SIMD_IMPLEMENTATION:STRING=std
CMAKE_ARGS_i386=	-DLIBUNICODE_SIMD_IMPLEMENTATION:STRING=std
CMAKE_ARGS_powerpc64=	-DLIBUNICODE_SIMD_IMPLEMENTATION:STRING=sse2
CMAKE_ARGS_powerpc64le=	-DLIBUNICODE_SIMD_IMPLEMENTATION:STRING=sse2
CXXFLAGS_powerpc64=	-DNO_WARN_X86_INTRINSICS -D__SSE2__ -mvsx
CXXFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS -D__SSE2__

REINPLACE_ARGS=	-i ''

PORTDOCS=	README.md TODO.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/contour
	${MV} ${STAGEDIR}${PREFIX}/lib/*.* ${STAGEDIR}${PREFIX}/lib/contour
	${REINPLACE_CMD} -e 's|$${_IMPORT_PREFIX}/lib/|$${_IMPORT_PREFIX}/lib/contour/|' \
		${STAGEDIR}${PREFIX}/lib/cmake/libunicode/libunicode-targets-${CMAKE_BUILD_TYPE:tl}.cmake

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
