# $FreeBSD$

PORTNAME=	easyconfig
PORTVERSION=	0.1.7
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTVERSIONPREFIX=	v

MAINTAINER=	python@FreeBSD.org
COMMENT=	Library for loading configurations easily in Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>3.10:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>1.9.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	RussellLuo

.include <bsd.port.mk>
