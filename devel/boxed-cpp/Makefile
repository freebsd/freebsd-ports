PORTNAME=	boxed-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.3
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Boxing primitive types in C++
WWW=		https://github.com/contour-terminal/boxed-cpp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${LOCALBASE}/lib/cmake/Catch2/Catch2Config.cmake:devel/catch2

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	contour-terminal

CMAKE_TESTING_ON=	BOXED_TESTING

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
