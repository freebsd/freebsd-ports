# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	lark-parser
PORTVERSION=	0.11.3
PORTREVISION=	1
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

OPTIONS_DEFINE=	ATOMIC_CACHE NEARLEY REGEX
OPTIONS_DEFAULT=ATOMIC_CACHE REGEX
ATOMIC_CACHE_DESC=	Multiprocess caching and crash recovery support
NEARLEY_DESC=		Import grammars from Nearley.js
REGEX_DESC=		Use third-party regex instead of standard library re

ATOMIC_CACHE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atomicwrites>=0:devel/py-atomicwrites@${PY_FLAVOR}
NEARLEY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Js2Py>=0:devel/py-Js2Py@${PY_FLAVOR}
REGEX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR}

.include <bsd.port.mk>
