PORTNAME=	spotipy
DISTVERSION=	2.25.2
PORTREVISION=	0
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Light weight Python library for the Spotify Web API
WWW=		https://github.com/spotipy-dev/spotipy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=3.5.3:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.15.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.0:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	spotipy-dev
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	CACHE DOCS #EXAMPLES

CACHE_DESC=		Enable a cache handler via pymemcache
CACHE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymemcache>=4.0.0:databases/py-pymemcache@${PY_FLAVOR}
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.8.0,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>=1.0.0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
DOCS_PORTDOCS=		* .buildinfo
#EXAMPLES_PORTEXAMPLES=	*

post-install-DOCS-on:
	${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} -d ${WRKDIR} -b html ${WRKSRC}/docs ${STAGEDIR}${DOCSDIR}

#post-install-EXAMPLES-on:
#	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>
