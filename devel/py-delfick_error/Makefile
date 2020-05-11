# $FreeBSD$

PORTNAME=	delfick_error
PORTVERSION=	1.7.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Customized exception class

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}total-ordering>0:devel/py-total-ordering@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}noseofyeti>=1.4.9:devel/py-noseofyeti@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	\
		${PY_SPHINX} \
		${PYTHON_PKGNAMEPREFIX}cloud_sptheme>0:textproc/py-cloud_sptheme@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_GITHUB=	yes
GH_ACCOUNT=	delfick
GH_TAGNAME=	6761e6c
USE_PYTHON=	autoplist distutils

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|sphinx-build|&-${PYTHON_VER}|' ${WRKSRC}/docs/build.sh

post-build-DOCS-on:
	cd ${WRKSRC}/docs && ${SH} build.sh

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/_build/html ; \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-not -name .buildinfo")

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m nose --with-noy

.include <bsd.port.mk>
