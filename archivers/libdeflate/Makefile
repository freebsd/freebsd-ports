PORTNAME=	libdeflate
PORTVERSION=	1.15
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	98174ac5e6fe2a806923bcb6bfa24cdbf32c79d0.patch:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast, whole-buffer DEFLATE-based compression library
WWW=		https://github.com/ebiggers/libdeflate

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	ebiggers
USE_LDCONFIG=	yes
CMAKE_ON=	LIBDEFLATE_USE_SHARED_LIB
CMAKE_TESTING_ON=	LIBDEFLATE_BUILD_TESTS

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/-O2 -DNDEBUG/d' ${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
