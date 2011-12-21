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

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6
JAVA_OS=	linux
JAVA_VENDOR=	sun
DESKTOP_ENTRIES=	"Minecraft" "Block building game" "${DATADIR}/Grass.png" "minecraft-client" "Application;Game;" false

do-install:
	echo "#!/bin/sh" >  ${WRKDIR}/minecraft-client
	echo "export JAVA_HOME=${JAVA_HOME}" >>  ${WRKDIR}/minecraft-client
	echo "exec java -Xmx1024M -Xms1024M -jar ${DATADIR}/minecraft.jar" >>  ${WRKDIR}/minecraft-client
	${MKDIR} ${DATADIR}
	(${INSTALL_DATA} "${DISTDIR}/minecraft.jar" ${DATADIR}/)
	(${INSTALL_DATA} "${DISTDIR}/Grass.png" ${DATADIR}/)
	(${INSTALL_SCRIPT} "${WRKDIR}/minecraft-client" ${PREFIX}/bin/)

.include <bsd.port.mk>
