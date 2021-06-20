# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	moto
PORTVERSION=	2.0.10
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Allow your python tests to easily mock out the boto library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.9.201:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}botocore>=1.12.201:devel/py-botocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.9.2:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1<3.0.0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.5:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0.9.0:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0:devel/py-xmltodict@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aws-xray-sdk>=0:devel/py-aws-xray-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto>=0:devel/py-boto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docker>=0:sysutils/py-docker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Cors>=0:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsondiff>=0:devel/py-jsondiff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-jose>=0:security/py-python-jose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sure>=0:devel/py-sure@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
