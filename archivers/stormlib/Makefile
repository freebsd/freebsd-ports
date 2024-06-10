PORTNAME=	stormlib
PORTVERSION=	9.26
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to process MPQ (MoPaQ) archives
WWW=		http://www.zezula.net/en/mpq/main.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtomcrypt.so:security/libtomcrypt

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	ladislav-zezula
GH_PROJECT=	StormLib
CMAKE_ON=	BUILD_SHARED_LIBS WITH_LIBTOMCRYPT

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_SUB=	yes

TEST_CMAKE_BOOL=STORM_BUILD_TESTS
TEST_LIB_DEPENDS=libasound.so:audio/alsa-lib

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
