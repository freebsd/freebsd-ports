PORTNAME=	Cura
DISTVERSION=	4.13.1
PORTREVISION=	4
PORTEPOCH=	2
CATEGORIES=	cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	Slicing application for 3D printers
WWW=		https://github.com/Ultimaker/Cura/wiki

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired devel/libsavitar and devel/py-pynest2d
EXPIRATION_DATE=2024-07-31

BUILD_DEPENDS=	Uranium>0,1:cad/uranium
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zeroconf>0:net/py-zeroconf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>0:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy-stl>0:math/py-numpy-stl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		qt5-graphicaleffects>0:graphics/qt5-graphicaleffects \
		qt5-quickcontrols>0:x11-toolkits/qt5-quickcontrols \
		qt5-quickcontrols2>0:x11-toolkits/qt5-quickcontrols2 \
		Uranium>=${DISTVERSION}:cad/uranium \
		libCharon>=4.13.0:net/libcharon \
		CuraEngine>=${DISTVERSION}:cad/cura-engine \
		fdm_materials>=4.13.0:cad/fdm_materials \
		${PYTHON_PKGNAMEPREFIX}trimesh>0:devel/py-trimesh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynest2d>=4.12.1:devel/py-pynest2d@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>0:devel/py-sentry-sdk@${PY_FLAVOR} \
		libArcus>=${DISTVERSION}:net/libarcus \
		libSavitar>=${DISTVERSION}:devel/libsavitar
LIB_DEPENDS=	libArcus.so:net/libarcus \
		libSavitar.so:devel/libsavitar

USES=		cmake gettext shebangfix python pyqt:5 \
		desktop-file-utils shared-mime-info
USE_PYQT=	pyqt5
CMAKE_ARGS+=	-DURANIUM_SCRIPTS_DIR:STRING="${LOCALBASE}/share/uranium/scripts" \
	-DCURA_VERSION=${DISTVERSION}
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
NO_ARCH=	yes
SHEBANG_FILES=	cura_app.py

pre-configure:
	${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|' \
		${WRKSRC}/CMakeLists.txt

post-patch:
	${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKSRC}/cura_app.py

.include <bsd.port.mk>
