# $FreeBSD$

PORTNAME=	vitables
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.2
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
DOS2UNIX_FILES=	setup.py
USE_GITHUB=	yes
GH_ACCOUNT=	uvemas
GH_PROJECT=	ViTables
USE_PYTHON=	distutils cython noflavors autoplist
USE_PYQT=	core_run gui_run sip_run widgets_run
NO_ARCH=	yes

PLIST_FILES=	${PYTHON_SITELIBDIR}/${PORTNAME}.sh

post-patch:
	@${REINPLACE_CMD} "s|version=read('VERSION')|version='${DISTVERSION}'|" ${WRKSRC}/setup.py

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}.sh
	@(echo "#!/bin/sh"; \
	  echo "LD_PRELOAD=${PREFIX}/lib/gcc${GCC_DEFAULT}/libgcc_s.so ${PYTHON_SITELIBDIR}/${PORTNAME}.sh \"\$$@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
