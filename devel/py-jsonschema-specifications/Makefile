PORTNAME=	jsonschema-specifications
PORTVERSION=	2024.10.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/python-jsonschema/jsonschema-specifications/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jsonschema_specifications-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Schema meta-schemas and vocabularies, exposed as a Registry
WWW=		https://github.com/python-jsonschema/jsonschema-specifications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}referencing>=0.31.0:devel/py-referencing@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
