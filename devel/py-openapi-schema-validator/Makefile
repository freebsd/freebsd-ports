# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	openapi-schema-validator
PORTVERSION=	0.2.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenAPI schema validation for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=3.0.0<5.0.0:devel/py-jsonschema@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ISODATE RFC3339_VALIDATOR STRICT_RFC3339
ISODATE_DESC=		Datetime validator via isodate
RFC3339_VALIDATOR_DESC=	Datetime validator via rfc3339-validator
STRICT_RFC3339_DESC=	Datetime validator via strict-rfc3339

ISODATE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isodate>=0:devel/py-isodate@${PY_FLAVOR}
RFC3339_VALIDATOR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rfc3339-validator>=0:devel/py-rfc3339-validator@${PY_FLAVOR}
STRICT_RFC3339_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}strict-rfc3339>=0:devel/py-strict-rfc3339@${PY_FLAVOR}

.include <bsd.port.mk>
