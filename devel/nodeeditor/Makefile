PORTNAME=	nodeeditor
DISTVERSION=	3.0.12
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Qt Node Editor, Dataflow programming framework
WWW=		https://github.com/paceholder/nodeeditor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
TEST_DEPENDS=	libCatch2>=0:devel/catch2

USES=		cmake gl qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	paceholder
USE_GL=		gl
USE_QT=		base

CMAKE_OFF=		BUILD_DOCS BUILD_TESTING
# The test doesn't work - it tries to run test_main, but
# ${WRKSRC}/test/test_main.cpp is empty.
#CMAKE_TESTING_ON=	BUILD_TESTING
#CMAKE_TESTING_OFF=	BUILD_TESTING

PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES
EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/* ${STAGEDIR}${EXAMPLESDIR}/bin
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

#pre-test:
#	${REINPLACE_CMD} 's|<catch2/catch.hpp>|<catch2/catch_all.hpp>|' \
		${test_main.cpp \
		src/TestUIInteraction.cpp \
		src/TestDataFlow.cpp \
		src/TestConnectionId.cpp \
		src/TestNodeDelegateModelRegistry.cpp \
		src/TestBasicGraphicsScene.cpp \
		src/TestAbstractGraphModelSignals.cpp \
		src/TestDataFlowGraphModel.cpp \
		src/TestUndoCommands.cpp \
		src/TestSerialization.cpp \
		src/TestAbstractGraphModel.cpp \
		:L:S|^|${WRKSRC}/test/|}

.include <bsd.port.mk>
