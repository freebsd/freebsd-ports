# $FreeBSD$

PORTNAME=	orange3-single-cell
DISTVERSION=	0.7.0
CATEGORIES=	biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Orange add-on for gene expression of single cell data

LICENSE=	AGPLv3+

RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYTHON_PKGNAMEPREFIX}orange3-bioinformatics>0:biology/py-orange3-bioinformatics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.20:math/py-pandas@${PY_FLAVOR}

USES=		python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	biolab
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gmake:devel/gmake \
			${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}

pre-build-DOCS-on:
	@cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} html htmlhelp SPHINXBUILD=${LOCALBASE}/bin/sphinx-build-${PYTHON_VER}

pre-build-DOCS-off:
	@${REINPLACE_CMD} "s|^    include_documentation|    #include_documentation|" ${WRKSRC}/setup.py

.include <bsd.port.mk>
