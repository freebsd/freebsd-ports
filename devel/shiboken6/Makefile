PORTNAME=	shiboken6
DISTVERSION=	${PYSIDE6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/pyside6/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-everywhere-src-${DISTVERSION}
DIST_SUBDIR=	KDE/Qt/${PYSIDE6_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python binding generator for C++ libraries
WWW=		http://qt-project.org

LICENSE=	GPLv2 LGPL21 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}shiboken6-tools>=${PYSIDE6_VERSION}:devel/shiboken6-tools@${PY_FLAVOR}
#RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}shiboken6-tools>=${PYSIDE6_VERSION}:devel/shiboken6-tools@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang python qt:6 tar:xz
USE_LDCONFIG=	${PREFIX}/${PORTNAME}
USE_PYTHON=	flavors

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD_LIBRARIES=-lexecinfo \
		-DUSE_PYTHON_VERSION=${PYTHON_VER} \
		-DBUILD_TESTS:BOOL=false


WRKSRC_SUBDIR=	sources/shiboken6
PLIST_SUB=	PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER} \
		SHLIB_VER=${DISTVERSION:R} \
		SHLIB_VERSION=${DISTVERSION}

OPTIONS_DEFINE=		DOCS NUMPY
OPTIONS_DEFAULT=	NUMPY

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}furo>0:textproc/py-furo@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}myst-parser>0:textproc/py-myst-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx-copybutton>0:textproc/py-sphinx-copybutton@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx-design>0:textproc/py-sphinx-design@${PY_FLAVOR}
DOCS_BINARY_ALIAS=	sphinx-build=sphinx-build-${PYTHON_VER}
DOCS_ALL_TARGET=	all doc
DOCS_PORTDOCS=		*

NUMPY_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
NUMPY_CMAKE_ON=		-DNUMPY_INCLUDE_DIR:PATH="${PYTHON_SITELIBDIR}/numpy/_core/include"

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/shiboken_tool.py
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	(cd ${BUILD_WRKSRC}/doc/html; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html)

.include <bsd.port.mk>
