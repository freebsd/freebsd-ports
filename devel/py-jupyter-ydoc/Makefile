PORTNAME=	jupyter-ydoc
PORTVERSION=	3.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/jupyter-server/jupyter_ydoc/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_ydoc-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Document structures for collaborative editing using Ypy
WWW=		https://jupyter-ydoc.readthedocs.io/en/latest/ \
		https://github.com/jupyter-server/jupyter_ydoc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-nodejs-version>=0:devel/py-hatch-nodejs-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.10.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrdt>=0.10.1<0.13.0:devel/py-pycrdt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
