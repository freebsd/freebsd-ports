PORTNAME=	scikit-hep-testdata
DISTVERSION=	0.6.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	scikit_hep_testdata-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Example HEP files for testing and demonstrating
WWW=		https://github.com/scikit-hep/scikit-hep-testdata

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>3.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		REQUESTS_CA_BUNDLE=/etc/ssl/cert.pem \
		SSL_CERT_FILE=/etc/ssl/cert.pem
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 0.6.8: 9 passed in 3.44s

.include <bsd.port.mk>
