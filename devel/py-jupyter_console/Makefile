PORTNAME=	jupyter_console
PORTVERSION=	6.2.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	IPython-like terminal frontend for Jupyter kernels in any language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-client>=0:devel/py-jupyter-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.0.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel5>=5.0.0:devel/py-ipykernel5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=2.0.0<3.1.0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${PY_FLAVOR}

USES=		python:3.7+

USE_PYTHON=	distutils autoplist
USE_LOCALE=	en_US.UTF-8
NO_ARCH=	yes

.include <bsd.port.mk>
