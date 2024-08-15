PORTNAME=	aiohttp-apispec
DISTVERSION=	3.0.0b1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	build and document REST APIs with aiohttp and apispec
WWW=		https://github.com/maximdanilchenko/aiohttp-apispec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}apispec>0:devel/py-apispec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webargs>0:www/py-webargs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
