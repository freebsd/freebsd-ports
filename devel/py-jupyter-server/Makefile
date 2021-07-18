# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	jupyter-server
PORTVERSION=	1.9.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_server-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	The backend to Jupyter web applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.1.0<4:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argon2-cffi>=0:security/py-argon2-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>=0:devel/py-ipython_genutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-client>=6.1.1:devel/py-jupyter-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-core>=4.6.0:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbconvert>=0:devel/py-nbconvert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=17:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-unixsocket>=0:www/py-requests-unixsocket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>=0:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}terminado>=0.8.3:net/py-terminado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.1.0:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.2.1:devel/py-traitlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=0:www/py-websocket-client@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
