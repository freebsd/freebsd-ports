PORTNAME=	Cura
DISTVERSION=	5.7.0
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	Slicing application for 3D printers
WWW=		https://github.com/Ultimaker/Cura/wiki

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	Uranium>0,1:cad/uranium
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zeroconf>0:net/py-zeroconf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>0:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy-stl>0:math/py-numpy-stl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		Uranium>=${DISTVERSION}:cad/uranium \
		libCharon>=5.0.0:net/libcharon \
		CuraEngine>=${DISTVERSION}:cad/cura-engine \
		fdm_materials>=${DISTVERSION}:cad/fdm_materials \
		${PYTHON_PKGNAMEPREFIX}trimesh>0:devel/py-trimesh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynest2d>=5.3.0:devel/py-pynest2d@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>0:devel/py-sentry-sdk@${PY_FLAVOR} \
		libArcus>=5.3.0:net/libarcus \
		libSavitar>=5.3.0:devel/libsavitar
LIB_DEPENDS=	libArcus.so:net/libarcus \
		libSavitar.so:devel/libsavitar

USES=		cmake gettext shebangfix python pyqt:6 \
		desktop-file-utils shared-mime-info
USE_PYQT=	pyqt6
CMAKE_ARGS+=	-DURANIUM_DIR:STRING="${LOCALBASE}/share/uranium" \
		-DCURA_VERSION:STRING=${DISTVERSION}
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
NO_ARCH=	yes
SHEBANG_FILES=	cura_app.py

#pre-configure:
#	${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|' \
#		${WRKSRC}/CMakeLists.txt
#
#post-patch:
#	${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
#		${WRKSRC}/cura_app.py

post-extract:
	@${MKDIR} ${WRKSRC}/cmake
	@for f in CuraPluginInstall.cmake CuraTests.cmake mod_bundled_packages_json.py; do \
		${CP} ${FILESDIR}/$$f ${WRKSRC}/cmake; \
		done
	@for f in CMakeLists.txt com.ultimaker.cura.desktop.in com.ultimaker.cura.appdata.xml; do \
		${CP} ${FILESDIR}/$$f ${WRKSRC}; \
		done
	@${CP} ${FILESDIR}/CuraVersion.py.in ${WRKSRC}/cura

.include <bsd.port.mk>
