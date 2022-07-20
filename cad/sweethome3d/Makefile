PORTNAME=	sweethome3d
PORTVERSION=	7.0
CATEGORIES=	cad java
MASTER_SITES=	SF/${PORTNAME}/SweetHome3D-source/${DISTNAME}/
DISTNAME=	SweetHome3D-${PORTVERSION}-src
DISTFILES=	${DISTNAME}.zip

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Free interior 3D design application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.TXT

BUILD_DEPENDS=	cmake:devel/cmake java3d>=0:java/java3d
RUN_DEPENDS=	java3d>=0:java/java3d

USE_ANT=	yes
USE_JAVA=	8

USE_GITHUB=	nodefault
GH_ACCOUNT=	puybaret:yr
GH_PROJECT=	libYafaRay:yr
GH_TAGNAME=	ef20db1:yr

ALL_TARGET=	jarExecutable
JARNAME=	SweetHome3D-${PORTVERSION}.jar

SUB_FILES=	sweethome3d.sh
SUB_LIST=	JARNAME=${JARNAME}

PLIST_FILES=	bin/sweethome3d \
		${JAVAJARDIR}/${JARNAME} \
		share/pixmaps/sweethome3d-icon.png

DESKTOP_ENTRIES="Sweet Home 3D" "" "${PORTNAME}-icon" "${PORTNAME}" "" false

build-yafaray:
	@${SED} -e '/^set(WITH_/s,ON),OFF),' \
		${WRKSRC_yr}/CMakeConfig/UserConfig.template \
		> ${WRKSRC_yr}/CMakeConfig/UserConfig.txt
	cd ${WRKSRC_yr} && cmake \
		-DUSER_INSTALL_PREFIX:PATH=${BUILD_WRKSRC}/build/yafaray \
		. && ${MAKE_CMD} VERBOSE=1 install
	${MV} ${BUILD_WRKSRC}/build/yafaray/lib/* ${BUILD_WRKSRC}/lib/yafaray

pre-build: build-yafaray
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} build
	cd ${BUILD_WRKSRC} && ${JAVAH} -jni -o \
		src/com/eteks/sweethome3d/j3d/YafarayRenderer.h -cp \
		classes:lib/j3dcore.jar:lib/vecmath.jar:build/SweetHome3D.jar \
		com.eteks.sweethome3d.j3d.YafarayRenderer
	cd ${BUILD_WRKSRC} && ${CXX} ${CXXFLAGS} -fPIC -std=c++11 \
		-I${JAVA_HOME}/include -I${JAVA_HOME}/include/${OPSYS:tl} \
		-I${WRKSRC_yr}/include \
		src/com/eteks/sweethome3d/j3d/YafarayRenderer.cpp -shared \
		-o lib/yafaray/libyafarayjni.so \
		-Llib/yafaray -lyafaray_v3_core

do-install:
	${INSTALL_DATA} ${WRKSRC}/install/${JARNAME} \
		${STAGEDIR}${JAVAJARDIR}/${JARNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/sweethome3d.sh \
		${STAGEDIR}${PREFIX}/bin/sweethome3d
	${INSTALL_DATA} ${WRKSRC}/deploy/SweetHome3DIcon32x32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/sweethome3d-icon.png

.include <bsd.port.mk>
