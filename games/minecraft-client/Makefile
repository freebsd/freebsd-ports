# New ports collection makefile for:   minecraft-client
# Date created:        12 November 2011
# Whom:                Martin Kropfinger
#
# $FreeBSD$
#

PORTNAME=	minecraft-client
PORTVERSION=	1.0.0
CATEGORIES=	games java
MASTER_SITES=	http://s3.amazonaws.com/MinecraftDownload/launcher/:minecraft \
				http://www.minecraftwiki.net/images/c/c5/:icon
DISTNAME=	minecraft
DISTFILES=	minecraft.jar:minecraft \
			Grass.png:icon
EXTRACT_ONLY=

MAINTAINER=	freebsd@rakor-net.de
COMMENT=	Client for the block building game

OPTIONS=	NATIVE_LIBS "Enable native libs support" off

.include <bsd.port.options.mk>

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6
DESKTOP_ENTRIES=	"Minecraft" "Block building game" "${DATADIR}/Grass.png" "minecraft-client" "Application;Game;" false

.if defined(WITH_NATIVE_LIBS)
USE_OPENAL=	soft
BUILD_DEPENDS+=	${JAVALIBDIR}/lwjgl/lwjgl_util.jar:${PORTSDIR}/games/lwjgl
RUN_DEPENDS+=	${JAVALIBDIR}/lwjgl/lwjgl_util.jar:${PORTSDIR}/games/lwjgl
JAVA_OS=	native
JAVA_VENDER=	openjdk
.else
JAVA_OS=	linux
JAVA_VENDOR=	sun
.endif

do-install:
	${ECHO_CMD} "#!/bin/sh" >  ${WRKDIR}/minecraft-client
	${ECHO_CMD} "export JAVA_HOME=${JAVA_HOME}" >>  ${WRKDIR}/minecraft-client
.if defined(WITH_NATIVE_LIBS) 
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
	                  xargs -0 rm -v\""                          >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "${ECHO_MSG} \"\""                                          >> ${WRKDIR}/minecraft-client
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
	${ECHO_CMD} "  if [ -f \$${BIN}/\$${j} -a ! -L \$${BIN}/\$${j} ]"   >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  then"                                                >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    target=\$$(${BASENAME} \$${j} .jar)"               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    eval target=\\\$$\$${target}"                      >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    ${LN} -snf \$${target} \$${BIN}/\$${j}"            >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  fi"                                                  >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "done"                                                  >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} ""                                                      >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "lwjgl=\"\$${NATIVES}/liblwjgl.so\""                    >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "lwjgl64=\"\$${NATIVES}/liblwjgl64.so\""                >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "if [ -f \$${lwjgl} -a ! -L \$${lwjgl} -a \
                   -f \$${lwjgl64} -a ! -L \$${lwjgl64} ]; then"     >> ${WRKDIR}/minecraft-client 
	${ECHO_CMD} "  LIBLWJGL=\$$(${FIND} ${LOCALBASE}/lib/lwjgl* \
                        -name 'liblwjgl*.so' | ${HEAD} -n 1)"        >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  LWJGLSO=\$$(${ECHO} \$${LIBJGL} | ${GREP} \"64\")"   >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  if [ \"x\$${LIBWJGLSO}\" = \"x\" ]; then"            >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    ${LN} -snf \$${LIBLWJGL} \$${lwjgl}"               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    ${LN} -snf liblwjgl.so \$${lwjgl64}"               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  else"                                                >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    ${LN} -snf \$${LIBLWJGL} \$${lwgjl64}"             >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "    ${LN} -snf liblwjgl64.so \$${lwgjl}"               >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "  fi"                                                  >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "fi"                                                    >> ${WRKDIR}/minecraft-client
	${ECHO_CMD} "exec java \$${JAVA_OPT} -jar ${DATADIR}/minecraft.jar" >> ${WRKDIR}/minecraft-client
.else
	${ECHO_CMD} "exec java -Xmx1024M -Xms1024M -jar ${DATADIR}/minecraft.jar" >>  ${WRKDIR}/minecraft-client
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} "${DISTDIR}/minecraft.jar" ${DATADIR}/
	${INSTALL_DATA} "${DISTDIR}/Grass.png" ${DATADIR}/
	${INSTALL_SCRIPT} "${WRKDIR}/minecraft-client" ${PREFIX}/bin/

.include <bsd.port.mk>
