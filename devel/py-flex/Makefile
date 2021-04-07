PORTNAME=	flex
DISTVERSION=	6.14.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Swagger schema validation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=3.3:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpointer>=1.7:devel/py-jsonpointer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3987>=1.3.4:www/py-rfc3987@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.7.3:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}strict-rfc3339>=0.7:devel/py-strict-rfc3339@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validate_email>=1.2:mail/py-validate_email@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
