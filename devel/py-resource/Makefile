# $FreeBSD$

PORTNAME=	resource
PORTVERSION=	0.2.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Library concentrated on the Resource layer of RESTful APIs

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonform>=0.0.2:devel/py-jsonform@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonsir>=0.0.2:devel/py-jsonsir@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}easyconfig>=0.1.0:devel/py-easyconfig@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	RussellLuo
GH_TAGNAME=	aee62d5

.include <bsd.port.mk>
