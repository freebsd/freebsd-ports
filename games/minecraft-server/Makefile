# $FreeBSD$

PORTNAME=	minecraft-server
PORTVERSION=	1.15.2
CATEGORIES=	games java
MASTER_SITES=	https://launcher.mojang.com/v1/objects/bb2b6b1aefcd70dfd1892149ac3a215f6c636b07/
DISTFILES=	server.jar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	freebsd@jonathanprice.org
COMMENT=	Dedicated server for the game Minecraft

LICENSE=	minecraft
LICENSE_NAME=	Minecraft End User License Agreement
LICENSE_TEXT=	The license can be viewed at: https://account.mojang.com/documents/minecraft_eula
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

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
DAEMON_RUN_DEPENDS=	tmux:sysutils/tmux

NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${STAGEDIR}${PREFIX}/${PORTNAME}
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
