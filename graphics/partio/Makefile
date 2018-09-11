# $FreeBSD$

PORTNAME=	partio
PORTVERSION=	1.5.5
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for manipulating animation particle formats

LICENSE=	BSD3CLAUSE

USES=		cmake:outsource gl shebangfix
SHEBANG_FILES=	src/tools/partedit.py src/tools/partjson.py
USE_GL=		gl glu glut
USE_LDCONFIG=	yes
USE_XORG=	xi

USE_GITHUB=	yes
GH_ACCOUNT=	wdas

OPTIONS_DEFINE=		DOCS PYTHON	# XXX: should probably use DOXYGEN
OPTIONS_DEFAULT=	PYTHON

PYTHON_BROKEN_OFF=	does not build without Python support

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
PYTHON_USES=		python
PYTHON_BUILD_DEPENDS=	swig3.0:devel/swig30
BINARY_ALIAS=	swig=swig3.0

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|python -c|${PYTHON_CMD} -c|' \
		${WRKSRC}/src/py/CMakeLists.txt \
		${WRKSRC}/src/tools/CMakeLists.txt
	@${REINPLACE_CMD} -e '/install(TARGETS/d' \
		${WRKSRC}/src/tests/CMakeLists.txt

post-patch-PYTHON-off:
	@${REINPLACE_CMD} -e '/ADD_SUBDIRECTORY.*src\/py.*/d' \
		${WRKSRC}/CMakeLists.txt

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/ADD_SUBDIRECTORY.*src\/doc.*/d' \
		${WRKSRC}/CMakeLists.txt

post-build-DOCS-on:
	@${MAKE_CMD} -C ${BUILD_WRKSRC} doc

.include <bsd.port.mk>
