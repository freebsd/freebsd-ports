PORTNAME=	stringzilla
DISTVERSIONPREFIX=	v
DISTVERSION=	3.10.6
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SIMD-accelerated string search/sort/hashes/fingerprints/edit distances
WWW=		https://ashvardanian.com/posts/stringzilla/ \
		https://github.com/ashvardanian/stringzilla

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ashvardanian
GH_PROJECT=	StringZilla

CMAKE_ON=	STRINGZILLA_INSTALL
CMAKE_ARGS=	-DSTRINGZILLA_INCLUDE_INSTALL_DIR=include

post-install: # https://github.com/ashvardanian/StringZilla/issues/188
	${INSTALL_LIB} ${BUILD_WRKSRC}/libstringzilla_shared.so.3.10.6 ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${BUILD_WRKSRC}/libstringzillite.so.3.10.6 ${STAGEDIR}${PREFIX}/lib
	@cd ${STAGEDIR}${PREFIX}/lib && \
		${LN} -s libstringzilla_shared.so.3.10.6 libstringzilla_shared.so.1 && \
		${LN} -s libstringzilla_shared.so.1 libstringzilla_shared.so
	@cd ${STAGEDIR}${PREFIX}/lib && \
		${LN} -s libstringzillite.so.3.10.6 libstringzillite.so.1 && \
		${LN} -s libstringzillite.so.1 libstringzillite.so

.include <bsd.port.mk>
