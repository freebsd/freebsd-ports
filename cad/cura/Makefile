# $FreeBSD$

PORTNAME=	Cura
DISTVERSION=	15.06.03-82
DISTVERSIONSUFFIX=	-g7c70ace
PORTEPOCH=	1
CATEGORIES=	cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	Slicing application for 3D printers

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	Uranium>0:cad/uranium
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt5-gui>0:x11-toolkits/py-qt5-gui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qt5-widgets>0:x11-toolkits/py-qt5-widgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qt5-qml>0:lang/py-qt5-qml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zeroconf>0:net/py-zeroconf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>0:devel/py-shapely@${PY_FLAVOR} \
		Uranium>0:cad/uranium \
		libCharon>0:net/libcharon \
		fdm_materials>0:cad/fdm_materials \
		${PYTHON_PKGNAMEPREFIX}trimesh>0:devel/py-trimesh@${PY_FLAVOR}
LIB_DEPENDS=	libArcus.so:net/libarcus \
		libSavitar.so:devel/libsavitar

USES=		cmake gettext shebangfix python:3.4+ desktop-file-utils shared-mime-info
CMAKE_ARGS+=	-DURANIUM_SCRIPTS_DIR:STRING="${LOCALBASE}/share/uranium/scripts"
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
USE_GITHUB=	yes
GH_TAGNAME=	7c70ace
NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKSRC}/cura_app.py

.include <bsd.port.mk>
