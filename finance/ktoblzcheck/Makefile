PORTNAME=	ktoblzcheck
PORTVERSION=	1.59
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Check bank codes of various financial institutions
WWW=		https://ktoblzcheck.sourceforge.net/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	${PORTNAME}-data>=1.0.0.20250609:finance/ktoblzcheck-data
TEST_DEPENDS=	${PORTNAME}-data>=1.0.0.20250609:finance/ktoblzcheck-data

USES=		cmake:testing localbase pathfix sqlite
USE_LDCONFIG=	yes

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Python3

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen \
				dot:graphics/graphviz
DOXYGEN_CMAKE_BOOL_OFF=		CMAKE_DISABLE_FIND_PACKAGE_Doxygen

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
