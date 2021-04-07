PORTNAME=	babi
PORTVERSION=	0.0.19
CATEGORIES=	editors python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Text Editor written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babi_grammars>=0:devel/py-babi_grammars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}identify>=0:devel/py-identify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onigurumacffi>=0.0.18:devel/py-onigurumacffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babi_grammars>=0:devel/py-babi_grammars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}identify>=0:devel/py-identify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onigurumacffi>=0.0.18:devel/py-onigurumacffi@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils flavors

.include <bsd.port.mk>
