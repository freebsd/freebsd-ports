# $FreeBSD$

PORTNAME=	delfick_error
PORTVERSION=	1.7.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Customized exception class

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}total-ordering>0:devel/py-total-ordering
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}noseofyeti>=1.4.9:devel/py-noseofyeti	\
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}cloud_sptheme>0:textproc/py-cloud_sptheme

NO_ARCH=	yes
USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	delfick
GH_TAGNAME=	6761e6c
USE_PYTHON=	autoplist distutils

PORTDOCS=	*

post-build-DOCS-on:
	cd ${WRKSRC}/docs && ${SH} build.sh

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/_build/html ; \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-not -name .buildinfo")

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m nose --with-noy

.include <bsd.port.mk>
