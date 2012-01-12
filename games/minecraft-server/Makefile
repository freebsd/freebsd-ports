# New ports collection makefile for:   minecraft-client
# Date created:        12 November 2011
# Whom:                Martin Kropfinger
#
# $FreeBSD$
#

PORTNAME=	minecraft-server
PORTVERSION=	1.0.1
CATEGORIES=	games java
MASTER_SITES=	http://s3.amazonaws.com/MinecraftDownload/launcher/:minecraft \
		http://www.minecraftwiki.net/images/f/f7/:icon
DISTNAME=	minecraft_server
DISTFILES=	minecraft_server.jar:minecraft \
		Bookshelf.png:icon
EXTRACT_ONLY=

MAINTAINER=	freebsd@rakor-net.de
COMMENT=	Server for the block building game

RUN_DEPENDS=	tmux:${PORTSDIR}/sysutils/tmux

OPTIONS=	X11	"Build with X11 support" On

ETCDIR=		${PREFIX}/etc/minecraft

.include <bsd.port.options.mk>

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_JAVA=	yes
USERS?=		mcserver
GROUPS?=	${USERS}
USE_RC_SUBR=	minecraft
SUB_FILES=	pkg-deinstall \
		pkg-message

PLIST_SUB+=	USERS=${USERS} \
		GROUPS=${GROUPS}

.if !defined(WITHOUT_X11)
DESKTOP_ENTRIES="Minecraft-Server" "Block building game (server)" "${DATADIR}/Bookshelf.png" "minecraft-server" "Application;Game;" false
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
	${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/server.properties.sample ${DATADIR}/server.properties.sample
	${INSTALL_DATA} ${FILESDIR}/ops.txt.sample ${DATADIR}/ops.txt.sample
	${INSTALL_DATA} ${FILESDIR}/white-list.txt.sample ${DATADIR}/white-list.txt.sample
	${INSTALL_DATA} ${FILESDIR}/banned-ips.txt.sample ${DATADIR}/banned-ips.txt.sample
	${INSTALL_DATA} ${FILESDIR}/banned-players.txt.sample ${DATADIR}/banned-players.txt.sample
	if [ ! -f ${ETCDIR}/server.properties ]; then \
		${CP} -p ${DATADIR}/server.properties.sample ${ETCDIR}/server.properties ; \
	fi
	if [ ! -f ${ETCDIR}/ops.txt ]; then \
		${CP} -p ${DATADIR}/ops.txt.sample ${ETCDIR}/ops.txt ; \
	fi
	if [ ! -f ${ETCDIR}/white-list.txt ]; then \
		${CP} -p ${DATADIR}/white-list.txt.sample ${ETCDIR}/white-list.txt ; \
	fi
	if [ ! -f ${ETCDIR}/banned-ips.txt ]; then \
		${CP} -p ${DATADIR}/banned-ips.txt.sample ${ETCDIR}/banned-ips.txt ; \
	fi
	if [ ! -f ${ETCDIR}/banned-players.txt ]; then \
		${CP} -p ${DATADIR}/banned-players.txt.sample ${ETCDIR}/banned-players.txt ; \
	fi
	${LN} -s ${ETCDIR}/server.properties ${DATADIR}/server.properties
	${LN} -s ${ETCDIR}/ops.txt ${DATADIR}/ops.txt
	${LN} -s ${ETCDIR}/white-list.txt ${DATADIR}/white-list.txt
	${LN} -s ${ETCDIR}/banned-ips.txt ${DATADIR}/banned-ips.txt
	${LN} -s ${ETCDIR}/banned-players.txt ${DATADIR}/banned-players.txt
	${CHOWN} -R ${USERS}:${GROUPS} ${DATADIR}
	${CHOWN} -R ${USERS}:${GROUPS} ${ETCDIR}
	${CHMOD} -R 644 ${DATADIR}/banned-ips.txt
	${CHMOD} -R 644 ${DATADIR}/banned-players.txt
	${CHMOD} -R 644 ${DATADIR}/ops.txt
	${CHMOD} -R 644 ${DATADIR}/white-list.txt
	${CHMOD} -R 644 ${DATADIR}/server.properties
	${CHMOD} -R 644 ${DATADIR}/banned-ips.txt.sample
	${CHMOD} -R 644 ${DATADIR}/banned-players.txt.sample
	${CHMOD} -R 644 ${DATADIR}/ops.txt.sample
	${CHMOD} -R 644 ${DATADIR}/white-list.txt.sample
	${CHMOD} -R 644 ${DATADIR}/server.properties.sample
	${CHMOD} -R 644 ${ETCDIR}/banned-ips.txt
	${CHMOD} -R 644 ${ETCDIR}/banned-players.txt
	${CHMOD} -R 644 ${ETCDIR}/ops.txt
	${CHMOD} -R 644 ${ETCDIR}/white-list.txt
	${CHMOD} -R 644 ${ETCDIR}/server.properties

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
