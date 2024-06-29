PORTNAME=	3d
DISTVERSION=	${PYQT3D_VERSION}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITES_PYQT3D}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQT3D_DISTNAME}

PYQT_DIST=	yes

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 3D framework
WWW=		https://www.riverbankcomputing.com/software/pyqt3d/

BUILD_DEPENDS=	${PY_SETUPTOOLS}

USES=		gl pyqt:6 python qt:6
USE_GL=		opengl
USE_PYQT=	sip:build pyqt6 qtbuilder:build
USE_PYTHON=	concurrent flavors
USE_QT=		3d base

PLIST_SUB=	PYQT3D_VERSION=${DISTVERSION} \
		PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER} \
		PYTHON_MAJOR_VER_regex=[[:<:]]${PYTHON_MAJOR_VER}[[:>:]]

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt6 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
