PORTNAME=	datasette
PORTVERSION=	0.64.8
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source multi-tool for exploring and publishing data
WWW=		https://datasette.io/ \
		https://github.com/simonw/datasette

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiofiles>=0.4:devel/py-aiofiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asgi-csrf>=0.9:www/py-asgi-csrf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asgiref>=3.2.10:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.1.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-default-group>=1.2.3:devel/py-click-default-group@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.20:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hupper>=1.9:devel/py-hupper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>=1.1:security/py-itsdangerous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}janus>=0.6.2:devel/py-janus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mergedeep>=1.1.1:devel/py-mergedeep@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>=0.9:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=1.0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.11:www/py-uvicorn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
