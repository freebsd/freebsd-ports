PORTNAME=	napari-plugin-engine
DISTVERSION=	0.2.1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	napari_plugin_engine-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Napari plugin management package
WWW=		https://napari-plugin-engine.readthedocs.io/en/latest/ \
		https://github.com/napari/napari-plugin-engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 0.2.1: 119 passed

.include <bsd.port.mk>
