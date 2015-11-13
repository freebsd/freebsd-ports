# $FreeBSD$

PORTNAME=	minecraft-server
PORTVERSION=	1.8.8
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	https://s3.amazonaws.com/Minecraft.Download/versions/${PORTVERSION}/
DISTFILES=	minecraft_server.${PORTVERSION}.jar
EXTRACT_ONLY=

MAINTAINER=	freebsd@jonathanprice.org
COMMENT=	Dedicated server for the game Minecraft

OPTIONS_SINGLE=		RUN
OPTIONS_SINGLE_RUN=	DAEMON STANDALONE

DAEMON_DESC=		Run as a service
STANDALONE_DESC=	Run the .jar file directly
OPTIONS_SUB=		yes

OPTIONS_DEFAULT=	STANDALONE

USERS=		mcserver
GROUPS=		${USERS}

NO_BUILD=	yes
USE_JAVA=	yes
SUB_FILES=	minecraft-server \
		pkg-message \
		pkg-deinstall
SUB_LIST=	VERSION=${PORTVERSION}
PLIST_SUB=	VERSION=${PORTVERSION}

CONFIG_FILES=	banned-ips.json \
		banned-players.json \
		eula.txt \
		ops.json \
		server.properties \
		usercache.json \
		whitelist.json

DAEMON_VARS=	USE_RC_SUBR=minecraft
DAEMON_RUN_DEPENDS=	tmux:${PORTSDIR}/sysutils/tmux

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/var/db/minecraft-server
	${MKDIR} ${STAGEDIR}/var/log/minecraft-server
.for file in ${CONFIG_FILES}
	${LN} -s ${ETCDIR}/${file} ${STAGEDIR}${PREFIX}/${PORTNAME}/${file}
.endfor
	${LN} -sf /var/log/minecraft-server ${STAGEDIR}${PREFIX}/${PORTNAME}/logs
	${LN} -sf /var/log/minecraft-server/debug ${STAGEDIR}${PREFIX}/${PORTNAME}/debug
	${LN} -sf /var/db/minecraft-server ${STAGEDIR}${PREFIX}/${PORTNAME}/world

post-install-STANDALONE-on:
	${INSTALL_SCRIPT} ${WRKDIR}/minecraft-server ${STAGEDIR}${PREFIX}/bin
	${CP} ${FILESDIR}/java-args.txt ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
