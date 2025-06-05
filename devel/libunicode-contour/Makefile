PORTNAME=	libunicode
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-contour

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Modern C++20 Unicode library
WWW=		https://github.com/contour-terminal/libunicode

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/cmake/Catch2/Catch2Config.cmake:devel/catch2 \
		UCD>=16.0.0,1:textproc/UCD

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	contour-terminal

USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLIBUNICODE_UCD_DIR:STRING=${LOCALBASE}/share/unicode/ucd \
		${CMAKE_ARGS_${ARCH}}
CMAKE_ARGS_i386=	-DLIBUNICODE_SIMD_IMPLEMENTATION:STRING=std

CONFLICTS_INSTALL=	libunicode

PORTDOCS=	README.md TODO.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
