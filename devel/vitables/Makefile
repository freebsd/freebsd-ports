# $FreeBSD$

PORTNAME=	vitables
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.2
PORTREVISION=	6
CATEGORIES=	devel science python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Viewer and editor of files in both PyTables format and HDF5 format

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=1.2.1:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numexpr>=2.0:math/py-numexpr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tables>=3.0:devel/py-tables@${PY_FLAVOR}

USES=		dos2unix python pyqt:5
USE_PYTHON=	distutils cython noflavors autoplist
USE_PYQT=	core_run gui_run sip_run widgets_run

USE_GITHUB=	yes
GH_ACCOUNT=	uvemas
GH_PROJECT=	ViTables

DOS2UNIX_FILES=	setup.py

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} "s|version=read('VERSION')|version='${DISTVERSION}'|" ${WRKSRC}/setup.py

.include <bsd.port.mk>
