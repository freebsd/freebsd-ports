# Created by: Martin Kropfinger
# $FreeBSD$

PORTNAME=	minecraft-client
PORTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	http://s3.amazonaws.com/MinecraftDownload/launcher/:minecraft \
		http://media-mcw.cursecdn.com/c/c5/:icon
DISTNAME=	minecraft
DISTFILES=	minecraft.jar:minecraft \
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
JAVA_VERSION=	1.6
DESKTOP_ENTRIES="Minecraft" \
		"Block building game" \
		"${PREFIX}/share/pixmaps/minecraft-client.png" \
		"${PORTNAME}" \
		"Game;Java;" \
		false

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNATIVE_LIBS}
USE_OPENAL=	soft
RUN_DEPENDS+=	${JAVALIBDIR}/lwjgl/lwjgl_util.jar:${PORTSDIR}/games/lwjgl
JAVA_OS=	native
JAVA_VENDOR=	openjdk
.else
JAVA_OS=	linux
JAVA_VENDOR=	sun
.endif

do-install:
	${ECHO_CMD} "#!/bin/sh" >  ${WRKDIR}/minecraft-client
	${ECHO_CMD} "export JAVA_HOME=${JAVA_HOME}" >>  ${WRKDIR}/minecraft-client
.if ${PORT_OPTIONS:MNATIVE_LIBS}
	${ECHO_CMD} "${ECHO_MSG} \"Note:\""                                     >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"\""                                          >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"  Please restart this script after inital\"" >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"  downloading all the Minecraft files,   \"" >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"  some of the libraries will be replaced \"" >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"  with FreeBSD-compiled version. Also,   \"" >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"  run the following command to remove    \"" >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"  the symlinks before doing any upgrade: \"" >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"\""                                          >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"find ~/.minecraft/bin -type l -print0 | \
			${XARGS} -0 ${RM} -v\""                                 >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"\""                                          >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"After deleting symlinks, you will have to\"" >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"force update to get replacements of all\""   >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"files that are normally used via symlinks.\"">> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "MINECRAFT_DIR=\"\$${HOME}/.minecraft\""                >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "BIN=\"\$${MINECRAFT_DIR}/bin\""                        >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "NATIVES=\"\$${MINECRAFT_DIR}/bin/natives\""            >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${MKDIR} \$${NATIVES}"                                 >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "jinput=\"${JAVAJARDIR}/jinput/jinput.jar\""            >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "lwjgl=\"${JAVAJARDIR}/lwjgl/lwjgl.jar\""               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "lwjgl_util=\"${JAVAJARDIR}/lwjgl/lwjgl_util.jar\""     >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "CP=\"\$${MINECRAFT_DIR}/minecraft.jar\""               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "CP=\"\$${CP}:${JAVAJARDIR}/jinput/jinput.jar\""        >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "CP=\"\$${CP}:${JAVAJARDIR}/jutils/jutils.jar\""        >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "JAVA_IP4=\"-Djava.net.preferIPv4Stack=true\""          >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "JAVA_OPT=\"-Dos.name=Linux\""                          >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "JAVA_OPT=\"\$${JAVA_OPT} -Xmx1024M -Xms512M\""         >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "JAVA_OPT=\"\$${JAVA_OPT} \$${JAVA_IP4}\""              >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "JAVA_OPT=\"\$${JAVA_OPT} -classpath \$${CP}\""         >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} ""                                                      >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "for j in jinput.jar lwjgl.jar lwjgl_util.jar"          >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "do"                                                    >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  if [ \( -f \$${BIN}/\$${j} -a ! -L \$${BIN}/\$${j} \) -o \
			\( -L \$${BIN}/\$${j} -a ! -f \$${BIN}/\$${j} \) ]" >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  then"                                                >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    target=\$$(${BASENAME} \$${j} .jar)"               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    eval target=\\\$$\$${target}"                      >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    ${LN} -snf \$${target} \$${BIN}/\$${j}"            >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  fi"                                                  >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "done"                                                  >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} ""                                                      >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "lwjgl=\"\$${NATIVES}/liblwjgl.so\""                    >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "lwjgl64=\"\$${NATIVES}/liblwjgl64.so\""                >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "if [ \( -f \$${lwjgl} -a ! -L \$${lwjgl} -a \
			-f \$${lwjgl64} -a ! -L \$${lwjgl64} \) -o \
			\( -L \$${lwjgl} -a ! -f \$${lwjgl} -a \
			-L \$${lwjgl64} -a ! -f \$${lwjgl64} \) ]; then" >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  LIBLWJGL=\$$(${FIND} ${LOCALBASE}/lib/lwjgl* \
			-name 'liblwjgl*.so' | ${HEAD} -n 1)"               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  LWJGLSO=\$$(${ECHO} \$${LIBJGL} | ${GREP} \"64\")"   >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  if [ \"x\$${LIBWJGLSO}\" = \"x\" ]; then"            >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    ${LN} -snf \$${LIBLWJGL} \$${lwjgl}"               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    ${LN} -snf liblwjgl.so \$${lwjgl64}"               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  else"                                                >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    ${LN} -snf \$${LIBLWJGL} \$${lwgjl64}"             >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    ${LN} -snf liblwjgl64.so \$${lwgjl}"               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  fi"                                                  >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "fi"                                                    >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} ""                                                      >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "libopenal=\"\$${NATIVES}/libopenal.so\""               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "libopenal64=\"\$${NATIVES}/libopenal64.so\""           >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "if [ \( -f \$${libopenal} -a ! -L \$${libopenal} -a \
			-f \$${libopenal64} -a ! -L \$${libopenal64} \) -o \
			\( -L \$${libopenal} -a ! -f \$${libopenal} -a \
			-L \$${libopenal64} -a ! -f \$${libopenal64} \) ]; then"  >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  ${LN} -snf ${LOCALBASE}/lib/libopenal.so \$${libopenal}"   >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  ${LN} -snf ${LOCALBASE}/lib/libopenal.so \$${libopenal64}" >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "fi"                                                    >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} ""                                                      >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "exec java \$${JAVA_OPT} -jar ${DATADIR}/minecraft.jar" >> ${WRKDIR}/minecraft-client
.else
	${ECHO_CMD} "exec java -Xmx1024M -Xms1024M -jar ${DATADIR}/minecraft.jar" >>  ${WRKDIR}/minecraft-client
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/minecraft.jar ${DATADIR}/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Grass.png ${PREFIX}/share/pixmaps/minecraft-client.png
	${INSTALL_SCRIPT} ${WRKDIR}/minecraft-client ${PREFIX}/bin/

.include <bsd.port.mk>
