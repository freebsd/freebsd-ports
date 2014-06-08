# Created by: Martin Kropfinger
# $FreeBSD$

PORTNAME=	minecraft-server
PORTVERSION=	1.4.7
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	http://assets.minecraft.net/${PORTVERSION:S|.|_|g}/ \
		http://media-mcw.cursecdn.com/f/f7/:icon
DISTNAME=	minecraft_server
DISTFILES=	minecraft_server.jar \
		Bookshelf.png:icon
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	#empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server for the block building game

RUN_DEPENDS=	tmux:${PORTSDIR}/sysutils/tmux

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

ETCDIR=		${PREFIX}/etc/minecraft

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_JAVA=	yes
USERS?=		mcserver
GROUPS?=	${USERS}
USE_RC_SUBR=	minecraft
SUB_FILES=	pkg-deinstall \
		pkg-message

SUB_LIST+=	USERS=${USERS} \
		GROUPS=${GROUPS}

CONFIG_FILES=	banned-ips.txt \
		banned-players.txt \
		ops.txt \
		server.properties \
		white-list.txt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
DESKTOP_ENTRIES="Minecraft-Server" \
		"Block building game (server)" \
		"${PREFIX}/share/pixmaps/minecraft-server.png" \
		"${PORTNAME}" \
		"Game;Java;" \
		false
.endif

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/minecraft_server.jar ${STAGEDIR}${DATADIR}/
.if ${PORT_OPTIONS:MX11}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Bookshelf.png ${STAGEDIR}${PREFIX}/share/pixmaps/minecraft-server.png
.endif
	echo "#!/bin/sh"				>  ${WRKDIR}/${PORTNAME}
	echo "if ! test -d ~/.minecraft-server ; then"	>> ${WRKDIR}/${PORTNAME}
	echo "	mkdir ~/.minecraft-server"		>> ${WRKDIR}/${PORTNAME}
	echo "fi"					>> ${WRKDIR}/${PORTNAME}
	echo "cd ~/.minecraft-server"			>> ${WRKDIR}/${PORTNAME}
	${CP} ${WRKDIR}/${PORTNAME} ${WRKDIR}/${PORTNAME}-nogui
	echo "java -Xmx1024M -Xms1024M -jar ${DATADIR}/minecraft_server.jar"		>> ${WRKDIR}/${PORTNAME}
	echo "java -Xmx1024M -Xms1024M -jar ${DATADIR}/minecraft_server.jar nogui"	>> ${WRKDIR}/${PORTNAME}-nogui
.if ${PORT_OPTIONS:MX11}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-nogui ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for file in ${CONFIG_FILES}
	${INSTALL_DATA} ${FILESDIR}/${file}.sample ${STAGEDIR}${ETCDIR}
	${CHMOD} 644 ${STAGEDIR}${ETCDIR}/${file}.sample
.endfor

.include <bsd.port.mk>
