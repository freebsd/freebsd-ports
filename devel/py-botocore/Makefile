# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>

PORTNAME=	botocore
PORTVERSION=	1.20.81
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bhughes@FreeBSD.org
COMMENT=	Low-level, core functionality of boto 3

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.1<3.0.0:devel/py-dateutil@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}jmespath>=0.7.1<1.0.0:devel/py-jmespath@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.25.4,1<1.27,1:net/py-urllib3@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# setup.py test runs integration tests which fail
# https://github.com/boto/s3transfer/issues/41
# Note: this is an AWS python package wide issue
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v tests/unit tests/functional

.include <bsd.port.mk>
