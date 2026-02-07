PORTNAME=	easy-thumbnails
DISTVERSION=	2.10.1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}django-
DISTNAME=	easy_thumbnails-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Easy thumbnails for Django
WWW=		https://github.com/SmileyChris/easy-thumbnails

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS SVG
OPTIONS_DEFAULT=	SVG
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PY_PILLOW}
SVG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}svglib>0:converters/py-svglib@${PY_FLAVOR}

post-build-DOCS-on:
	${SETENV} PYTHONPATH=${WRKSRC} ${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} \
		-d ${WRKDIR} -b html ${WRKSRC}/docs/ ${WRKSRC}/build/sphinx/html

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
