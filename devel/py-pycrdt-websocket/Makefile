PORTNAME=	pycrdt-websocket
PORTVERSION=	0.14.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/jupyter-server/pycrdt-websocket/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pycrdt_websocket-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WebSocket connector for pycrdt
WWW=		https://github.com/jupyter-server/pycrdt-websocket

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.6.2<5:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrdt>=0.9.0<0.10.0:devel/py-pycrdt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite-anyio>=0.2.3<0.3.0:databases/py-sqlite-anyio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DJANGO
DJANGO_DESC=	Django support

DJANGO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}channels>=0:www/py-channels@${PY_FLAVOR}

.include <bsd.port.mk>
