# $FreeBSD$

PORTNAME=	orange3-single-cell
DISTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Orange add-on for gene expression of single cell data

LICENSE=	AGPLv3+

RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYTHON_PKGNAMEPREFIX}orange3-bioinformatics>0:biology/py-orange3-bioinformatics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}astropy>0:astro/py-astropy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastdtw>0:math/py-fastdtw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=0.11:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}loompy>=2.0.10:biology/py-loompy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.23:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYNUMPY}

# Supports 3.4+ but loompy 3.6+ only.
USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	biolab
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gmake:devel/gmake \
			${PY_SPHINX}

pre-build-DOCS-on:
	@cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} html htmlhelp SPHINXBUILD=${LOCALBASE}/bin/sphinx-build-${PYTHON_VER}

pre-build-DOCS-off:
	@${REINPLACE_CMD} "s|^    include_documentation|    #include_documentation|" ${WRKSRC}/setup.py

.include <bsd.port.mk>
