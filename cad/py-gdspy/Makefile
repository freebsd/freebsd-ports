PORTNAME=	gdspy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.13
CATEGORIES=	cad python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Python module for creating GDSII stream files
WWW=		https://github.com/heitzmann/gdspy/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	pytest:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	heitzmann
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	EXAMPLES

post-install:
	cd ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} && \
	    ${STRIP_CMD} clipper*.so

post-install-EXAMPLES-on:
	cd ${WRKSRC}/tests && \
	    ${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
	    ${INSTALL_SCRIPT} *.py ${STAGEDIR}${EXAMPLESDIR} && \
	    ${INSTALL_DATA} *.gds ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/tools && \
	    ${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
	    ${INSTALL_SCRIPT} maketestgds.py ${STAGEDIR}${EXAMPLESDIR}

do-test:
	cd ${WRKSRC} && \
	    ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} \
	    ${LOCALBASE}/bin/pytest

.include <bsd.port.mk>
