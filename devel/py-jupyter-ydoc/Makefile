PORTNAME=	jupyter-ydoc
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/jupyter-server/jupyter_ydoc/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_ydoc-${PORTVERSION}

PATCH_SITES=	https://github.com/jupyter-server/jupyter_ydoc/commit/
PATCHFILES=	9b7635bdcebfa07e3234b0449c4ffe2a07aaa206.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Document structures for collaborative editing using Ypy
WWW=		https://jupyter-ydoc.readthedocs.io/en/latest/ \
		https://github.com/jupyter-server/jupyter_ydoc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-nodejs-version>=0:devel/py-hatch-nodejs-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.10.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.12.1<5.0.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrdt>=0.13.0<0.14.0:devel/py-pycrdt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
