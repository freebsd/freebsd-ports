PORTNAME=	dill
DISTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Serialize all of python
WWW=		https://dill.readthedocs.io/en/latest/ \
		https://github.com/uqfoundation/dill

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist # pytest doesn't work for dill, see https://github.com/uqfoundation/dill/issues/578#issuecomment-1455107267

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/dill/tests

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC}/dill/tests && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m dill.tests

.include <bsd.port.mk>
