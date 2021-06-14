# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	jupyter-server-mathjax
PORTVERSION=	0.2.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_server_mathjax-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MathJax resources as a Jupyter Server Extension

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-packaging>=0:devel/py-jupyter-packaging@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-server>=1.1<2:devel/py-jupyter-server@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
