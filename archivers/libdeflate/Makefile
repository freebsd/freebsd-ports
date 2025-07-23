PORTNAME=	libdeflate
DISTVERSION=	1.24
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/ebiggers/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast, whole-buffer DEFLATE-based compression library
WWW=		https://github.com/ebiggers/libdeflate

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing
USE_LDCONFIG=	yes

CMAKE_ON=	LIBDEFLATE_USE_SHARED_LIB
CMAKE_TESTING_ON=	LIBDEFLATE_BUILD_TESTS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
