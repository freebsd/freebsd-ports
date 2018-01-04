# $FreeBSD$

PORTNAME=	jupyter_console
PORTVERSION=	5.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	IPython-like terminal frontend for Jupyter kernels in any language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter_client>=0:devel/py-jupyter_client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=0:devel/py-ipykernel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt_toolkit>=1.0.4:devel/py-prompt_toolkit@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
USE_LOCALE=	en_US.UTF-8
NO_ARCH=	yes

.include <bsd.port.mk>
