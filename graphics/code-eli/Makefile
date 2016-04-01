# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	code-eli
PORTVERSION=	0.3.6
CATEGORIES=	graphics

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Library with functionalities for geometries

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	eigen>3:math/eigen3

USE_GITHUB=	yes
GH_PROJECT=	Code-Eli
GH_ACCOUNT=	ddmarshall

USES=		cmake:outsource compiler:c++11-lib
PORTEXAMPLES=	AirfoilFitExample VSPPodExample test
PORTDOCS=	html latex
ALL_TARGET=	all

# Some useful variables
AIRFOIL_DIR=	airfoil_fit
VSPPOD_DIR=	vsp_pod

# Build options
OPTIONS_DEFINE=		DOCS EXAMPLES
EXAMPLES_LIB_DEPENDS=	libcpptest.so:devel/cpptest
DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:devel/doxygen
DOCS_ALL_TARGET=	doc

# The code uses std::cbrt(). Even if one passes some additional macros for
# libstdc++ to enable additional math functions in math.h some of them, such as
# acoshl() are not defined and linking fails.
BROKEN_FreeBSD_9=	Needs additional math functions

post-patch-EXAMPLES-off:
	${REINPLACE_CMD} \
		-e 's/add_subdirectory(example)//g' \
		-e 's/find_package(CPPTest)//g' \
		${WRKSRC}/CMakeLists.txt

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/eli \
		${STAGEDIR}${EXAMPLESDIR}${TEST_SUBDIR} \
		${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/include/eli/code_eli.hpp \
		${STAGEDIR}${PREFIX}/include/eli
	(cd ${WRKSRC}/include/eli && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/eli "*")

do-install-EXAMPLES-on:
	${INSTALL_DATA} \
		${BUILD_WRKSRC}/example/${VSPPOD_DIR}/VSPPodExample \
		${BUILD_WRKSRC}/example/${AIRFOIL_DIR}/AirfoilFitExample \
		${STAGEDIR}${EXAMPLESDIR}
	${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/VSPPodExample \
		${STAGEDIR}${EXAMPLESDIR}/AirfoilFitExample
	(cd ${BUILD_WRKSRC}/${TEST_SUBDIR} && \
		${COPYTREE_BIN} . ${STAGEDIR}${EXAMPLESDIR}${TEST_SUBDIR} \
		"-name *Test -type f")
	${FIND} ${STAGEDIR}${EXAMPLESDIR}${TEST_SUBDIR} -name *Test | \
		${XARGS} ${STRIP_CMD}

do-install-DOCS-on:
	(cd ${BUILD_WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
