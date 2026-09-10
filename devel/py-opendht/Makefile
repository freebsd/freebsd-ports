PORTNAME=	opendht
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.0
CATEGORIES=	devel net
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight Distributed Hash Table implementation
WWW=		https://github.com/savoirfairelinux/opendht/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/predef/other/endian.h:devel/boost-libs
LIB_DEPENDS=	libopendht.so:devel/opendht \
		libgnutls.so:security/gnutls

USES=		cmake compiler:c++17-lang localbase python
USE_PYTHON=	distutils cython autoplist unittest

USE_GITHUB=	yes
GH_ACCOUNT=	savoirfairelinux

WRKSRC_SUBDIR=	python

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-extract:
	@${MV} ${WRKSRC}/tests/opendht_tests.py ${WRKSRC}/tests/test_opendht.py

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/opendht/_core*.so

# tests as of 4.4.0: 4 tests passed, 1 skipped in 2.031s (test_bootstrap skipped, network ping fails in sandbox; see https://github.com/savoirfairelinux/opendht/issues/683)

.include <bsd.port.mk>
