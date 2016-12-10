# $FreeBSD$

PORTNAME=		arduino
PORTVERSION=		1.6.12
PORTREVISION=		4
CATEGORIES=		devel java
PKGNAMESUFFIX=		16
DIST_SUBDIR=		${PORTNAME}

MAINTAINER=		bsdports@kyle-evans.net
COMMENT=		Open-source electronics prototyping platform

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/../license.txt

LIB_DEPENDS=		liblistSerialsj.so:devel/listserialc \
			libastyle-arduinoj.so:devel/libastylej-arduino
RUN_DEPENDS=		arduino-builder:devel/arduino-builder \
			arduino-tools>=1.6.12:devel/arduino-tools \
			bash:shells/bash \
			${JAVA_HOME}/jre/lib/ext/jssc-2.8.0.jar:comms/java-simple-serial-connector

CONFLICTS=		arduino-[0-9]*

BUNDLE_GH_ACCOUNT=	arduino-libraries
BUNDLE_LIBRARIES=	Firmata:2.5.3:firmata \
			Bridge:1.6.3:bridge \
			Robot_Control:1.0.2:robotcontrol \
			Robot_Motor:1.0.1:robotmotor \
			RobotIRremote:1.0.2:robotir \
			SpacebrewYun:1.0.1:spacebrew \
			Temboo:1.1.7:temboo \
			Esplora:1.0.4:esplora \
			Mouse:1.0.1:mouse \
			Keyboard:1.0.1:keyboard

GH_TUPLE+=		${BUNDLE_GH_ACCOUNT}:WiFi101-FirmwareUpdater-Plugin:v0.8.0:wifi10/linux/work/tools/WiFi101

USE_GITHUB=		yes
GH_ACCOUNT=		arduino
GH_PROJECT=		Arduino

.for blib in ${BUNDLE_LIBRARIES}
GH_TUPLE+=		${BUNDLE_GH_ACCOUNT}:${blib}/linux/work/libraries/${blib:C/\:.*//}
.endfor

USES=			desktop-file-utils
LIB_DIRS+=		${LOCALBASE}/lib ${LOCALBASE}/lib/jni
WRKSRC_SUBDIR=		build
PATCH_WRKSRC=		${WRKSRC}/../
MAKE_ARGS+=		-Dlight_bundle=true -Dlocal_sources=true
USE_JAVA=		yes
USE_ANT=		yes
DOCS_MAKE_ARGS=		-Dno_docs=false
DOCS_MAKE_ARGS_OFF=	-Dno_docs=true
OS_DIR=			${WRKSRC}/linux
BUILD_DIR=		${OS_DIR}/work
INSLIST=		lib libraries revisions.txt tools
STRIP=			# No Elfs here, only symlinks
OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_SUB=		yes

DOCS_MASTER_SITES=	http://downloads.arduino.cc/:ref,galileo,edison \
			https://files.kyle-evans.net/arduino/:ref,galileo,edison
DOCS_DISTFILES=		reference-1.6.6-3.zip:ref \
			Galileo_help_files-1.6.2.zip:galileo \
			Edison_help_files-1.6.2.zip:edison

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSLIST+=		reference
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
INSLIST+=		examples
.endif

post-extract:
	${MKDIR} ${BUILD_DIR}/reference
	${MV} ${WRKDIR}/code.jquery.com ${BUILD_DIR}/reference
	${MV} ${WRKDIR}/www.arduino.cc ${BUILD_DIR}/reference
	${MV} ${WRKDIR}/Galileo_help_files ${BUILD_DIR}/reference
	${MV} ${WRKDIR}/Edison_help_files ${BUILD_DIR}/reference

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${PATCH_WRKSRC}/arduino-core/src/processing/app/BaseNoGui.java
	${REINPLACE_CMD} -e 's:<BINARY_LOCATION>:arduino:' -e 's:<ICON_NAME>:arduino:' \
		${PATCH_WRKSRC}/build/linux/dist/desktop.template

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	(cd ${BUILD_DIR}/ && ${COPYTREE_SHARE} "${INSLIST}" ${STAGEDIR}${PREFIX}/${PORTNAME} ${FIND_EXPR})
	(cd ${WRKSRC}/../ && ${COPYTREE_SHARE} "libraries" ${STAGEDIR}${PREFIX}/${PORTNAME} ${FIND_EXPR})
	${RM} ${STAGEDIR}${PREFIX}/${PORTNAME}/lib/libastylej.so
	${RM} ${STAGEDIR}${PREFIX}/${PORTNAME}/lib/liblistSerialsj.so
	${RM} ${STAGEDIR}${PREFIX}/${PORTNAME}/lib/jssc-2.8.0.jar
	${LN} -s ../../lib/jni/libastyle-arduinoj.so ${STAGEDIR}${PREFIX}/${PORTNAME}/lib/libastylej.so
	${LN} -s ../../lib/jni/liblistSerialsj.so ${STAGEDIR}${PREFIX}/${PORTNAME}/lib/liblistSerialsj.so
	${INSTALL_SCRIPT} ${BUILD_DIR}/arduino ${STAGEDIR}${PREFIX}/${PORTNAME}
	${LN} -s ../${PORTNAME}/arduino ${STAGEDIR}${PREFIX}/bin/arduino
	${LN} -s ../bin/arduino-builder ${STAGEDIR}${PREFIX}/arduino/arduino-builder
	${CP} ${WRKSRC}/shared/icons/arduino.xpm ${STAGEDIR}/${PREFIX}/share/pixmaps
	${CP} ${PATCH_WRKSRC}/build/linux/dist/desktop.template ${STAGEDIR}/${PREFIX}/share/applications/arduino.desktop

.include <bsd.port.mk>
