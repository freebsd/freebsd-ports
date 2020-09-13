# $FreeBSD$

PORTNAME=	partio
PORTVERSION=	1.13.0
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

OPTIONS_DEFINE=		DOCS DOXYGEN EXAMPLES

# DOCS must be selected for PORTDOCS to work
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doc

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's,OpenGL::OpenGL,$${OPENGL_LIBRARIES},' \
		${WRKSRC}/src/tools/CMakeLists.txt

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/add_subdirectory(src\/doc)/d' \
		${WRKSRC}/CMakeLists.txt

# Remove those files that don't yet work
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/partedit ${STAGEDIR}${PREFIX}/bin/partinspect

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/src/doc && ${INSTALL_DATA} tutorial.txt partio.tex ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/src/data && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
