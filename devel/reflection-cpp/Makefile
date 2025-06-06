PORTNAME=	reflection-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	C++ static reflection support library
WWW=		https://github.com/contour-terminal/reflection-cpp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${LOCALBASE}/lib/cmake/Catch2/Catch2Config.cmake:devel/catch2

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	contour-terminal

CMAKE_TESTING_ON=	REFLECTION_TESTING

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
