PORTNAME=	tartiflette-aiohttp
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Run Tartiflette GraphQL Engine through aiohttp
WWW=		https://github.com/tartiflette/tartiflette-aiohttp

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.5.4:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tartiflette>=0.12.0<2.0.0:devel/py-tartiflette@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
