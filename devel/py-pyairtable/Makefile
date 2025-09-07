PORTNAME=	pyairtable
PORTVERSION=	3.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Client for the Airtable API
WWW=		https://pyairtable.readthedocs.io/en/stable/ \
		https://github.com/gtalarico/pyairtable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}inflection>=0:devel/py-inflection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2<3:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26,1:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CLI

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR}

.include <bsd.port.mk>
