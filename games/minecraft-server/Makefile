# $FreeBSD$

PORTNAME=	minecraft-server
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	https://s3.amazonaws.com/Minecraft.Download/versions/${PORTVERSION}/
DISTNAME=	minecraft_server.${PORTVERSION}.jar
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	freebsd@jonathanprice.org
COMMENT=	Dedicated server for the game Minecraft

ETCDIR=		${PREFIX}/etc/minecraft-server

USERS=		mcserver
GROUPS=		${USERS}

NO_BUILD=	yes
USE_JAVA=	yes
SUB_FILES=	pkg-message \
		pkg-deinstall

CONFIG_FILES=	banned-ips.json \
		banned-players.json \
		ops.json \
		server.properties \
		usercache.json \
		whitelist.json

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/var/db/minecraft-server
	${MKDIR} ${STAGEDIR}/var/log/minecraft-server
	${INSTALL_SCRIPT} ${FILESDIR}/minecraft-server ${STAGEDIR}${PREFIX}/bin
.for file in ${CONFIG_FILES}
	${LN} -s ${ETCDIR}/${file} ${STAGEDIR}${DATADIR}/${file}
.endfor
	${LN} -sf /var/log/minecraft-server ${STAGEDIR}${DATADIR}/logs
	${LN} -sf /var/log/minecraft-server/debug ${STAGEDIR}${DATADIR}/debug
	${LN} -sf /var/db/minecraft-server ${STAGEDIR}/${DATADIR}/world

.include <bsd.port.mk>
