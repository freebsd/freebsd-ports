PORTNAME=	reedsolo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.4
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Pure-Python Reed Solomon encoder/decoder

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	autoplist cython distutils

GH_ACCOUNT=	tomerfiliba
GH_PROJECT=	reedsolomon
TEST_ENV+=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@cd ${TEST_WRKSRC} && \
	${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} --with-coverage -d -v

.include <bsd.port.mk>
