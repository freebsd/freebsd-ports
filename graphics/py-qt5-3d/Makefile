PORTNAME=	3d
DISTVERSION=	${PYQT3D_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics devel python
MASTER_SITES=	${MASTER_SITES_PYQT3D}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQT3D_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, 3D module
WWW=		https://www.riverbankcomputing.com/software/pyqt3d/

LICENSE=	${PYQT5_LICENSE}

USES=		gl pyqt:5,dist python qt:5
USE_GL=		gl
USE_PYQT=	pyqt5 qtbuilder:build sip:build
USE_PYTHON=	concurrent flavors
USE_QT=		3d core declarative gui widgets \
		qmake:build

PLIST_SUB=      PYQT3D_VERSION=${DISTVERSION} \
		PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER} \
		PYTHON_MAJOR_VER_regex=[[:<:]]${PYTHON_MAJOR_VER}[[:>:]]

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
