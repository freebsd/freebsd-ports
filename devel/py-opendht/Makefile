PORTNAME=	opendht
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	devel net
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight Distributed Hash Table implementation
WWW=		https://github.com/savoirfairelinux/opendht/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/predef/other/endian.h:devel/boost-libs
LIB_DEPENDS=	libopendht.so:devel/opendht \
		libgnutls.so:security/gnutls

USES=		cmake compiler:c++17-lang localbase python
USE_PYTHON=	distutils cython autoplist unittest # 4 tests fail, see https://github.com/savoirfairelinux/opendht/issues/683

USE_GITHUB=	yes
GH_ACCOUNT=	savoirfairelinux

WRKSRC_SUBDIR=	python

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-extract:
	@${MV} ${WRKSRC}/tests/opendht_tests.py ${WRKSRC}/tests/test_opendht.py

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/opendht*.so

.include <bsd.port.mk>
