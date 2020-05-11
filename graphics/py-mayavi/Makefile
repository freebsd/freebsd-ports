# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	mayavi
PORTVERSION=	4.5.0
PORTREVISION=	7
CATEGORIES=	graphics science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Application and library for 3D visualization and plotting in Python

LICENSE=	BSD3CLAUSE LGPL21 LGPL20 EPL LGPL3 BSD2CLAUSE APACHE11
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_LGPL21=	${WRKSRC}/image_LICENSE_Nuvola.txt
LICENSE_FILE_LGPL20=	${WRKSRC}/image_LICENSE_CP.txt
LICENSE_FILE_EPL=	${WRKSRC}/image_LICENSE_Eclipse.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/image_LICENSE_OOo.txt
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE_YORICK.txt
LICENSE_FILE_APACHE11=	${WRKSRC}/LICENSE_COLORBREWER.txt
# See ${WRKSRC}/image_LICENSE.txt for per file license information

BUILD_DEPENDS=	vtk6>=6.1.0_8:math/vtk6 \
		${PY_SPHINX}
RUN_DEPENDS=	vtk6>=6.1.0_8:math/vtk6 \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}envisage>=4.4.0:devel/py-envisage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyface>=4.5.2:devel/py-pyface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scimath>=4.1.2:science/py-scimath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitsui>=4.5.1:graphics/py-traitsui@${PY_FLAVOR}

USES=		python:2.7 shebangfix tar:bzip2
USE_PYTHON=	autoplist distutils
USE_WX=		3.0+
WX_COMPS=	python:run
SHEBANG_FILES=	mayavi/tests/csv_files/csv_2_py

DEP1=		vtk6

pre-configure:
	if [ ! -e ${PREFIX}/lib/python2.7/site-packages/vtk/__init__.py ]; then \
		${ECHO_MSG} "Port math/vtk6 is installed without PYTHON option."; \
		${ECHO_MSG} "Please reinstall with PYTHON selected."; \
		${FALSE}; \
	else \
		${ECHO_MSG} "Good, math/vtk6 is installed with PYTHON option!"; \
	fi

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tvtk/array_ext.so

.include <bsd.port.mk>
