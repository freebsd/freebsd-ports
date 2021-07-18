# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	nbclient
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client library for executing notebooks

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}async_generator>=0:devel/py-async_generator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-client>=6.1.5:devel/py-jupyter-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=5.0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nest-asyncio>=0:devel/py-nest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.2:devel/py-traitlets@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
