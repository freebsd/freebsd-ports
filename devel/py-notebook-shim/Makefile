PORTNAME=	notebook-shim
PORTVERSION=	0.2.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	notebook_shim-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shim layer for notebook traits and config
WWW=		https://github.com/jupyter/notebook_shim

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-server>=1.8<3:devel/py-jupyter-server@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
