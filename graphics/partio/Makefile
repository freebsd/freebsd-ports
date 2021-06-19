PORTNAME=	partio
PORTVERSION=	1.14.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
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

OPTIONS_DEFINE=		DOCS DOXYGEN EXAMPLES PYQT
PYQT_DESC=		Install PyQt-based auxiliary tools

# DOCS must be selected for PORTDOCS to work
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doc

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

PYQT_USES=		pyqt:5
PYQT_USE=		PYQT=core,gui,widgets
PYQT_PLIST_FILES=	bin/partinspect

post-patch:
	@${REINPLACE_CMD} -e \
	    '/^project/s,${PORTNAME},& VERSION ${PORTVERSION},' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,OpenGL::OpenGL,$${OPENGL_LIBRARIES},' \
		${WRKSRC}/src/tools/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,^from Qt,from PyQt5,' \
		${WRKSRC}/src/tools/partinspect.py
	@${REINPLACE_CMD} -e '/^install/d' ${WRKSRC}/src/tests/CMakeLists.txt

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/add_subdirectory(src\/doc)/d' \
		${WRKSRC}/CMakeLists.txt

# Remove those files that don't yet work
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/partedit

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/src/doc && ${INSTALL_DATA} tutorial.txt partio.tex ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/src/data && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR}

post-install-PYQT-off:
	cd ${STAGEDIR}${PREFIX} && ${RM} ${PYQT_PLIST_FILES}

.include <bsd.port.mk>
