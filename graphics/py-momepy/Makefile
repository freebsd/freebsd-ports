PORTNAME=	momepy
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	PYPI \
		https://github.com/pysal/momepy/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Urban Morphology Measuring Toolkit
WWW=		https://docs.momepy.org/en/stable/ \
		https://github.com/pysal/momepy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}geopandas>=0.8.0:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpysal>=4.2.0:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.3:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygeos>=0:graphics/py-pygeos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.27.0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
