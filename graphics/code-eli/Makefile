# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	code-eli
PORTVERSION=	0.3.6
CATEGORIES=	graphics
MASTER_SITES=	GH

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Library with functionalities for geometries

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	eigen>3:${PORTSDIR}/math/eigen3

USE_GITHUB=	yes
GH_PROJECT=	Code-Eli
GH_ACCOUNT=	ddmarshall
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	2196ee5

USES=		cmake:outsource compiler:c++11-lib
PORTEXAMPLES=	AirfoilFitExample VSPPodExample test
PORTDOCS=	html latex
ALL_TARGET=	all

# Some useful variables
AIRFOIL_DIR=	airfoil_fit
VSPPOD_DIR=	vsp_pod

# Build options
OPTIONS_DEFINE=		DOCS EXAMPLES
EXAMPLES_LIB_DEPENDS=	libcpptest.so:${PORTSDIR}/devel/cpptest
DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
DOCS_ALL_TARGET=	doc

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} \
		-e 's/add_subdirectory(example)//g' \
		-e 's/find_package(CPPTest)//g' \
		${WRKSRC}/CMakeLists.txt
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/eli \
		${STAGEDIR}${EXAMPLESDIR}${TEST_SUBDIR} \
		${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/include/eli/code_eli.hpp \
		${STAGEDIR}${PREFIX}/include/eli
	(cd ${WRKSRC}/include/eli && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/eli "*")
.if ${PORT_OPTIONS:MEXAMPLES}
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
.endif
.if ${PORT_OPTIONS:MDOCS}
	(cd ${BUILD_WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
