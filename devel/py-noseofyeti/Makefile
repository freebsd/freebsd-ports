# $FreeBSD$

PORTNAME=	noseofyeti
PORTVERSION=	1.5.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Nose plugin providing BDD dsl for Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fudge>0:devel/py-fudge@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}should_dsl>0:devel/py-should_dsl@${FLAVOR}

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fudge>0:devel/py-fudge@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pinocchio>0:devel/py-pinocchio@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}should_dsl>0:devel/py-should_dsl@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	delfick
GH_PROJECT=	nose-of-yeti
GH_TAGNAME=	e8f3110
USE_PYTHON=	autoplist distutils
SHEBANG_FILES=	test.sh
PYTHON_OLD_CMD=	"/usr/bin/env python"

PORTDOCS=	*

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} test.sh

post-build-DOCS-on:
	(cd ${WRKSRC}/docs ; PYTHONPATH=${WRKSRC} ${MAKE_CMD} html)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/_build/html ; \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-not -name .buildinfo")

.include <bsd.port.mk>
