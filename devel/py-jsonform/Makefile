# $FreeBSD$

PORTNAME=	jsonform
PORTVERSION=	0.0.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Form validation for JSON-like data

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=2.4.0:devel/py-jsonschema@${PY_FLAVOR}

USES=		python:3.6+

USE_GITHUB=	yes
GH_ACCOUNT=	RussellLuo
GH_PROJECT=	jsonform
GH_TAGNAME=	7ee5f95
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
