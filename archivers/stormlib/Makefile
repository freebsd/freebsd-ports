PORTNAME=	stormlib
PORTVERSION=	9.23
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to process MPQ (MoPaQ) archives

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtomcrypt.so:security/libtomcrypt

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	ladislav-zezula
GH_PROJECT=	StormLib
CMAKE_ON=	BUILD_SHARED_LIBS WITH_LIBTOMCRYPT

OPTIONS_DEFINE=		DOCS

PORTDOCS=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
