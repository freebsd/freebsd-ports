PORTNAME=	stringzilla
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SIMD-accelerated string search/sort/hashes/fingerprints/edit distances
WWW=		https://ashvardanian.com/posts/stringzilla/ \
		https://github.com/ashvardanian/stringzilla

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ashvardanian
GH_PROJECT=	StringZilla

CMAKE_ON=	STRINGZILLA_INSTALL
CMAKE_OFF=	STRINGZILLA_BUILD_TEST
CMAKE_TESTING_ON=	STRINGZILLA_BUILD_TEST
CMAKE_ARGS=	-DSTRINGZILLA_INCLUDE_INSTALL_DIR=include

post-install:
	# workaround for https://github.com/ashvardanian/StringZilla/issues/194
	@${RM} -r ${STAGEDIR}/usr/src

.include <bsd.port.mk>
