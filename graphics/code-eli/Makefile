# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	code-eli
PORTVERSION=	0.3.6
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Library with functionalities for geometries

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN=		Needs work to use math/eigen3 currently in ports

USE_GITHUB=	yes
GH_PROJECT=	Code-Eli
GH_ACCOUNT=	ddmarshall

USES=		cmake:outsource compiler:c++11-lib eigen:3
PORTEXAMPLES=	AirfoilFitExample VSPPodExample test
ALL_TARGET=	all

# Some useful variables
AIRFOIL_DIR=	airfoil_fit
VSPPOD_DIR=	vsp_pod

# Build options
OPTIONS_DEFINE=		DOXYGEN EXAMPLES
EXAMPLES_LIB_DEPENDS=	libcpptest.so:devel/cpptest
DOXYGEN_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	doc
DOXYGEN_PORTDOCS=	html latex

BROKEN_armv6=		fails to compile: undefined reference to cbrtl
BROKEN_armv7=		fails to compile: undefined reference to cbrtl
BROKEN_powerpc64=	fails to compile: there are no arguments to 'printf' that depend on a template parameter

post-patch-EXAMPLES-off:
	${REINPLACE_CMD} \
		-e 's/add_subdirectory(example)//g' \
		-e 's/find_package(CPPTest)//g' \
		${WRKSRC}/CMakeLists.txt

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/eli
	${INSTALL_DATA} ${BUILD_WRKSRC}/include/eli/code_eli.hpp \
		${STAGEDIR}${PREFIX}/include/eli
	(cd ${WRKSRC}/include/eli && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/eli "*")

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}${TEST_SUBDIR} \
		${STAGEDIR}${EXAMPLESDIR}
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
		${XARGS} ${CHMOD} u+w
	${FIND} ${STAGEDIR}${EXAMPLESDIR}${TEST_SUBDIR} -name *Test | \
		${XARGS} ${STRIP_CMD}

do-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${BUILD_WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
