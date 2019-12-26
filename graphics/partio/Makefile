# $FreeBSD$

PORTNAME=	partio
PORTVERSION=	1.10.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for manipulating animation particle formats

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	swig3.0:devel/swig30

USES=		cmake compiler:c++11-lang gl python:2.7 shebangfix xorg
SHEBANG_FILES=	src/tools/partedit.py src/tools/partinspect.py \
		src/tools/partjson.py
USE_GL=		gl glu glut
USE_LDCONFIG=	yes
USE_XORG=	xi xmu

USE_GITHUB=	yes
GH_ACCOUNT=	wdas

OPTIONS_DEFINE=		DOCS DOXYGEN EXAMPLES
OPTIONS_DEFAULT=	DOCS

# DOCS must be selected for PORTDOCS to work
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doc

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

BINARY_ALIAS=	swig=swig3.0

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's|python -c|${PYTHON_CMD} -c|' \
		${WRKSRC}/src/py/CMakeLists.txt \
		${WRKSRC}/src/tools/CMakeLists.txt
	@${REINPLACE_CMD} -e '/install(TARGETS/d' \
		${WRKSRC}/src/tests/CMakeLists.txt

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/ADD_SUBDIRECTORY.*src\/doc.*/d' \
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
