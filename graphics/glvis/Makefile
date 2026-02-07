PORTNAME=	glvis
DISTVERSION=	4.4
CATEGORIES=	graphics
MASTER_SITES=	https://glvis.github.io/releases/
PKGNAMESUFFIX=	-mesh-visualizer # other software also has the name glvis
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight tool for accurate & flexible finite element visualization
WWW=		https://glvis.org \
		https://github.com/glvis/glvis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glm>0:math/glm \
		xxd:editors/vim
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libHYPRE.so:science/hypre \
		libmetis.so:math/metis \
		libmfem.so:math/mfem \
		libpng.so:graphics/png
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-image>0:graphics/py-scikit-image@${PY_FLAVOR}

USES=		cmake:testing gl mpi:mpich python:test sdl tar:tgz
USE_GL=		gl glew
USE_SDL=	sdl2

# the mpi dependency is inherited from math/mfem and not set here for simplicity

USE_GITHUB=	nodefault
GH_TUPLE=	GLVis:data:b8092cc:data/tests/data

CMAKE_TESTING_ON=	ENABLE_TESTS # 5 tests fail, likely because test baseline is for ubuntu
CMAKE_ARGS=	-DGLVIS_BASELINE_SYS=ubuntu-20.04 # baseline for tests

PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD}

do-install: # workaround for https://github.com/GLVis/glvis/issues/234
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/glvis ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
