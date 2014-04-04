# Created by: Martin Kropfinger
# $FreeBSD$

PORTNAME=	minecraft-client
PORTVERSION=	1.7.5
CATEGORIES=	games java
MASTER_SITES=	http://s3.amazonaws.com/Minecraft.Download/versions/${PORTVERSION}/:minecraft \
		http://media-mcw.cursecdn.com/c/c5/:icon
DISTFILES=	${PORTVERSION}.jar:minecraft \
		Grass.png:icon
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	janik@hikarihq.com
COMMENT=	Client for the block building game

OPTIONS_DEFINE=		NATIVE_LIBS
OPTIONS_DEFAULT=	NATIVE_LIBS
NATIVE_LIBS_DESC=	Enable native libs support

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7+
DESKTOP_ENTRIES="Minecraft" \
		"Block building game" \
		"${PREFIX}/share/pixmaps/minecraft-client.png" \
		"${PORTNAME}" \
		"Game;Java;" \
		false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNATIVE_LIBS}
USES+=		openal:soft
BUILD_DEPENDS+=	${JAVALIBDIR}/lwjgl/lwjgl_util.jar:${PORTSDIR}/games/lwjgl
RUN_DEPENDS+=	${JAVALIBDIR}/lwjgl/lwjgl_util.jar:${PORTSDIR}/games/lwjgl
JAVA_OS=	native
JAVA_VENDOR=	openjdk
PLIST_SUB+=	NATIVE=""
.else
JAVA_OS=	linux
JAVA_VENDOR=	sun
PLIST_SUB+=	NATIVE="@comment "
.endif

do-install:
	@${ECHO_CMD} "#!/bin/sh" 							>  ${WRKDIR}/minecraft-client
	@${ECHO_CMD} "export JAVA_HOME=${JAVA_HOME}" 					>> ${WRKDIR}/minecraft-client
	@${ECHO_CMD} "exec ${JAVA} -Xmx1024M -Xms1024M -jar ${DATADIR}/Minecraft.jar"	>> ${WRKDIR}/minecraft-client
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTVERSION}.jar \
		${STAGEDIR}${DATADIR}/Minecraft.jar
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Grass.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/minecraft-client.png
.if ${PORT_OPTIONS:MNATIVE_LIBS}
	@${MKDIR} ${WRKSRC}/native-libs
	@${CP} ${PREFIX}/lib/lwjgl*/liblwjgl*.so ${WRKSRC}/native-libs
	@${CP} ${PREFIX}/lib/libopenal.so ${WRKSRC}/native-libs
	@${JAR} cvf ${WRKSRC}/lwjgl-native-libs.jar -C ${WRKSRC}/native-libs .
	${INSTALL_DATA} -m 644 ${WRKSRC}/lwjgl-native-libs.jar \
		${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME} ${WRKDIR}
	${REINPLACE_CMD} \
		-e 's|=JAVA_HOME|=${JAVA_HOME}|' \
		-e 's|PREFIX|${PREFIX}|' \
		-e 's|JAVA_CMD|${JAVA}|' ${WRKDIR}/minecraft-client
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/minecraft-client ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
