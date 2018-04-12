# $FreeBSD$

PORTNAME=	boto3
PORTVERSION=	1.7.4
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
MAINTAINER=	python@FreeBSD.org
COMMENT=	AWS SDK for Python

RUN_DEPENDS=    ${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil@${FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}jmespath>=0.5.0:devel/py-jmespath@${FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}six>=1.8.0:devel/py-six@${FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}botocore>0:devel/py-botocore@${FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}s3transfer>0:net/py-s3transfer@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	boto


do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v tests/unit tests/functional

.include <bsd.port.mk>
