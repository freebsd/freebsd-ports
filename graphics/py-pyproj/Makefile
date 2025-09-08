PORTNAME=	pyproj
PORTVERSION=	3.7.2
CATEGORIES=	graphics geography python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cython wrapper to provide python interfaces to PROJ.4 functions
WWW=		https://pyproj4.github.io/pyproj/stable/ \
		https://github.com/pyproj4/pyproj

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	proj>=9.4.0,1:graphics/proj \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libproj.so:graphics/proj
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent cython3 pep517

MAKE_ENV=	PROJ_DIR=${LOCALBASE}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/sample.out ${WRKSRC}/test/test_*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
