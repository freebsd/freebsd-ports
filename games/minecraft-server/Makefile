# New ports collection makefile for:   minecraft-client
# Date created:        12 November 2011
# Whom:                Martin Kropfinger
#
# $FreeBSD$
#

PORTNAME=	minecraft-server
PORTVERSION=	1.0.0
CATEGORIES=	games java
MASTER_SITES=	http://s3.amazonaws.com/MinecraftDownload/launcher/:minecraft \
				http://www.minecraftwiki.net/images/f/f7/:icon
DISTNAME=		minecraft_server
DISTFILES=		minecraft_server.jar:minecraft \
				Bookshelf.png:icon
EXTRACT_ONLY=

MAINTAINER=		freebsd@rakor-net.de
COMMENT=		Server for the block building game

OPTIONS=		X11	"Build with X11 support" On

.include <bsd.port.options.mk>

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
USE_JAVA=		yes

.if !defined(WITHOUT_X11)
DESKTOP_ENTRIES=	"Minecraft-Server" "Block building game (server)" "${DATADIR}/Bookshelf.png" "minecraft-server" "Application;Game;" false
.endif

.if !defined(WITHOUT_X11)
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

do-install:
	${MKDIR} ${DATADIR}
	(${INSTALL_DATA} "${DISTDIR}/minecraft_server.jar" ${DATADIR}/)
.if !defined(WITHOUT_X11)
	(${INSTALL_DATA} "${DISTDIR}/Bookshelf.png" ${DATADIR}/)
.endif
	echo "#!/bin/sh" 								>  ${WRKDIR}/${PORTNAME}
	echo "if ! test -d ~/.minecraft-server ; then" 	>> ${WRKDIR}/${PORTNAME}
	echo "	mkdir ~/.minecraft-server" 				>> ${WRKDIR}/${PORTNAME}
	echo "fi" 										>> ${WRKDIR}/${PORTNAME}
	echo "cd ~/.minecraft-server"					>> ${WRKDIR}/${PORTNAME}
	${CP} ${WRKDIR}/${PORTNAME} ${WRKDIR}/${PORTNAME}-nogui
	echo "java -Xmx1024M -Xms1024M -jar ${DATADIR}/minecraft_server.jar" >> ${WRKDIR}/${PORTNAME}
	echo "java -Xmx1024M -Xms1024M -jar ${DATADIR}/minecraft_server.jar nogui" 	>> ${WRKDIR}/${PORTNAME}-nogui
.if !defined(WITHOUT_X11)
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-nogui ${PREFIX}/bin/

.include <bsd.port.mk>
