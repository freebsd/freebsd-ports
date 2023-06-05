PORTNAME=	jupyter-server-ydoc
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_server_ydoc-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Jupyter Server Extension Providing Y Documents
WWW=		https://github.com/jupyterlab/jupyter_collaboration

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0.25:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-server-fileid>=0.6.0<1:devel/py-jupyter-server-fileid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-ydoc>=0.2.0<0.4.0:devel/py-jupyter-ydoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ypy-websocket>=0.8.2<0.10.0_99:devel/py-ypy-websocket@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
