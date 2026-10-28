PORTNAME=	libunicode
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4
CATEGORIES=	devel
MASTER_SITES=	https://www.unicode.org/Public/${UCD_VERSION}/ucd/
PKGNAMESUFFIX=	-contour
DISTFILES=	UCD.zip
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}/${DISTVERSION}
EXTRACT_ONLY=	${DISTFILE_DEFAULT}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Modern C++20 Unicode library
WWW=		https://github.com/contour-terminal/libunicode

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/pkgconfig/catch2-with-main.pc:devel/catch2

USES=		cmake:testing python:build

USE_GITHUB=	yes
GH_ACCOUNT=	contour-terminal

USE_LDCONFIG=	${PREFIX}/lib/contour

CMAKE_ARGS=	-DLIBUNICODE_UCD_DIR:STRING=${UCD_DIR}

REINPLACE_ARGS=	-i ''

PLIST_SUB=	SOVERSION_FULL=${DISTVERSION} \
		SOVERSION_MAJOR_MINOR=${DISTVERSION:R}
PORTDOCS=	README.md TODO.md

OPTIONS_DEFINE=	DOCS

# libunicode-contour does not support Unicode 18.0.0 yet.
UCD_VERSION=	17.0.0
UCD_DIR=	${WRKSRC}/ucd

post-extract:
	@${MKDIR} ${WRKSRC}/ucd
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/UCD.zip ${EXTRACT_AFTER_ARGS} \
		-C ${UCD_DIR}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/contour
	${MV} ${STAGEDIR}${PREFIX}/lib/*.* ${STAGEDIR}${PREFIX}/lib/contour
	${REINPLACE_CMD} -e 's|$${_IMPORT_PREFIX}/lib/|$${_IMPORT_PREFIX}/lib/contour/|' \
		${STAGEDIR}${PREFIX}/lib/cmake/libunicode/libunicode-targets-${CMAKE_BUILD_TYPE:tl}.cmake

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
