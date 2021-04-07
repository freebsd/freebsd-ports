PORTNAME=	gdspy
PORTVERSION=	1.6
DISTVERSIONPREFIX=	v
CATEGORIES=	cad python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Python module for creating GDSII stream files

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	pytest:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	heitzmann

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_PLIST_FILES=	\
	${EXAMPLESDIR}/cell.py \
	${EXAMPLESDIR}/cellarray.py \
	${EXAMPLESDIR}/cellreference.py \
	${EXAMPLESDIR}/curve.py \
	${EXAMPLESDIR}/flexpath.py \
	${EXAMPLESDIR}/functions.py \
	${EXAMPLESDIR}/gdslibrary.py \
	${EXAMPLESDIR}/gdswriter.py \
	${EXAMPLESDIR}/polygonset.py \
	${EXAMPLESDIR}/robustpath.py \
	${EXAMPLESDIR}/test.gds \
	${EXAMPLESDIR}/tutils.py \
	${EXAMPLESDIR}/maketestgds.py

test:
	cd ${WRKSRC} && \
	    ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} \
	    ${LOCALBASE}/bin/pytest

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

.include <bsd.port.mk>
