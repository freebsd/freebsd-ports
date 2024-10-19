PORTNAME=	vitables
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.3
PORTREVISION=	1
CATEGORIES=	devel science python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Viewer and editor of files in both PyTables format and HDF5 format
WWW=		https://github.com/uvemas/ViTables

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=2.2:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numexpr>=2.0:math/py-numexpr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tables>=3.0:devel/py-tables@${PY_FLAVOR}

USES=		dos2unix python pyqt:5
USE_PYTHON=	pep517 cython noflavors autoplist pytest # 3 tests fail, see https://github.com/uvemas/ViTables/issues/124
USE_PYQT=	pyqt5:run

USE_GITHUB=	yes
GH_ACCOUNT=	uvemas
GH_PROJECT=	ViTables

NO_ARCH=	yes

.include <bsd.port.mk>
