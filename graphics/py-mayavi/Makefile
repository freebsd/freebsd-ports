PORTNAME=	mayavi
DISTVERSION=	4.9.0
CATEGORIES=	graphics science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Application and library for 3D visualization and plotting in Python
WWW=		http://code.enthought.com/pages/mayavi-project.html

LICENSE=			BSD3CLAUSE LGPL21 LGPL20 EPL LGPL3 BSD2CLAUSE APACHE11 # see ${WRKSRC}/image_LICENSE.txt
LICENSE_COMB=			multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_LGPL21=		${WRKSRC}/image_LICENSE_Nuvola.txt
LICENSE_FILE_LGPL20=		${WRKSRC}/image_LICENSE_CP.txt
LICENSE_FILE_EPL=		${WRKSRC}/image_LICENSE_Eclipse.txt
LICENSE_FILE_LGPL3=		${WRKSRC}/image_LICENSE_OOo.txt
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE_YORICK.txt
LICENSE_FILE_APACHE11=		${WRKSRC}/LICENSE_COLORBREWER.txt

BROKEN_i386=	stage fails: Building TVTK classes... Fatal Python error: Illegal instruction

LIB_DEPENDS=	libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apptools>0:devel/py-apptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}envisage>0:devel/py-envisage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyface>=6.1.1:devel/py-pyface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}puremagic>0:sysutils/py-puremagic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traits>=6.0.0:devel/py-traits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitsui>=7.0.0:graphics/py-traitsui@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	distutils autoplist pytest

USE_WX=		3.2
WX_COMPS=	python:run

SHEBANG_FILES=	mayavi/scripts/mayavi2 \
		mayavi/tests/csv_files/csv_2_py

PLIST_FILES=	${PYTHON_SITELIBDIR}/tvtk/tvtk_classes.zip

TEST_ENV+=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ENV+=	ETS_TOOLKIT=null QT_QPA_PLATFORM=offscreen # no GUI: do all rendering offscreen

do-test:
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} \
		-m pytest \
		--disable-plugin-autoload -p timeout -v --timeout=60 \
		${WRKSRC}/tvtk \
		--ignore=${WRKSRC}/tvtk/tests/test_browser.py \
		--ignore=${WRKSRC}/tvtk/tests/test_qt_x11.py \
		--ignore=${WRKSRC}/tvtk/tests/test_qvtk_render_window_interactor.py \
		--ignore=${WRKSRC}/tvtk/tests/test_tvtk_scene.py \
		--ignore=${WRKSRC}/tvtk/tests/test_visual.py

# tests as of 4.9.0: 115 passed, 8 skipped, 1 xpassed

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
