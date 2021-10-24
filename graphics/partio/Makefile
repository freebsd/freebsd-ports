PORTNAME=	partio
PORTVERSION=	1.14.6
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics math

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	C++ library for particle I/O and manipulation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig:devel/swig

USES=		cmake compiler:c++11-lang gl python:run shebangfix xorg
SHEBANG_FILES=	src/tools/partedit.py src/tools/partinspect.py \
		src/tools/partjson.py
USE_GL=		gl glu glut
USE_LDCONFIG=	yes
USE_XORG=	xi xmu

USE_GITHUB=	yes
GH_ACCOUNT=	wdas

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS DOXYGEN EXAMPLES PYQT TEST
PYQT_DESC=	Install PyQt-based auxiliary tools

# DOCS must be selected for PORTDOCS to work
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doc

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

PYQT_USES=		pyqt:5
PYQT_USE=		PYQT=pyqt5
PYQT_PLIST_FILES=	bin/partedit bin/partinspect

TEST_LIB_DEPENDS=	libgtest.so:devel/googletest
TEST_CMAKE_ON=		-DPARTIO_GTEST_ENABLED:BOOL=ON
TEST_VARS=		SHEBANG_FILES+="src/tests/testpartio.py \
			src/tests/testpartjson.py"

post-patch:
	@${REINPLACE_CMD} -e \
		'/^project/s,${PORTNAME},& VERSION ${PORTVERSION}, ; \
		s,/usr,${LOCALBASE},' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,^from Qt,from PyQt5,' \
		${WRKSRC}/src/tools/partedit.py \
		${WRKSRC}/src/tools/partinspect.py

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/add_subdirectory(src\/doc)/d' \
		${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/src/doc && ${INSTALL_DATA} tutorial.txt partio.tex ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/src/data && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR}

post-install-PYQT-off:
	cd ${STAGEDIR}${PREFIX} && ${RM} ${PYQT_PLIST_FILES}

do-test-TEST-on:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
