# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lark-parser
PORTVERSION=	0.11.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern parsing library for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	NEARLEY REGEX
OPTIONS_DEFAULT=REGEX
NEARLEY_DESC=	Import grammars from Nearley.js
REGEX_DESC=	Use third-party regex instead of standard library re

NEARLEY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Js2Py>=0:devel/py-Js2Py@${PY_FLAVOR}
REGEX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR}

.include <bsd.port.mk>
