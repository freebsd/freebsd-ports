# $FreeBSD$

PORTNAME=	noseofyeti
PORTVERSION=	1.8
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Nose plugin providing BDD dsl for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fudge>0:devel/py-fudge@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}should_dsl>0:devel/py-should_dsl@${PY_FLAVOR}

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fudge>0:devel/py-fudge@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pinocchio>0:devel/py-pinocchio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}should_dsl>0:devel/py-should_dsl@${PY_FLAVOR}

USES=		python:2.7 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	delfick
GH_PROJECT=	nose-of-yeti
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

SHEBANG_FILES=	test.sh
PYTHON_OLD_CMD=	"/usr/bin/env python"

PORTDOCS=	*

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} test.sh

post-build-DOCS-on:
	(cd ${WRKSRC}/docs ; PYTHONPATH=${WRKSRC} ${MAKE_CMD} html SPHINXBUILD=sphinx-build-${PYTHON_VER})

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/_build/html ; \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-not -name .buildinfo")

.include <bsd.port.mk>
