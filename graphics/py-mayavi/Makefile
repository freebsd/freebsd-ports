PORTNAME=	mayavi
DISTVERSION=	4.8.2
PORTREVISION=	5
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

BUILD_DEPENDS=	${PYNUMPY} \
		${PY_SPHINX} \
		sphinx-build:textproc/py-sphinx@${PY_FLAVOR}
LIB_DEPENDS=	libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}apptools>0:devel/py-apptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}envisage>0:devel/py-envisage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyface>=6.1.1:devel/py-pyface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traits>=6.0.0:devel/py-traits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitsui>=7.0.0:graphics/py-traitsui@${PY_FLAVOR} # list is in mayavi/__init__.py

USES=		python shebangfix
USE_PYTHON=	distutils autoplist

USE_WX=		3.2
WX_COMPS=	python:run

SHEBANG_FILES=	mayavi/scripts/mayavi2 \
		mayavi/tests/csv_files/csv_2_py

POST_PLIST=	fix-plist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tvtk/array_ext*.so

fix-plist:
	@${REINPLACE_CMD} -e "s|${PYTHONPREFIX_SITELIBDIR:S/${PREFIX}\///}/mayavi/preferences/__pycache__$$||" ${TMPPLIST}
	@${REINPLACE_CMD} -e "s|${PYTHONPREFIX_SITELIBDIR:S/${PREFIX}\///}/tvtk/plugins/scene/__pycache__$$||" ${TMPPLIST}

do-test:
	@${SETENV} ${TEST_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${PYTHON_CMD} ${WRKSRC}/examples/mayavi/interactive/coil_design_application.py

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
