PORTNAME=	minecraft-server
PORTVERSION=	1.19
CATEGORIES=	games java
MASTER_SITES=	https://launcher.mojang.com/v1/objects/e00c4052dac1d59a1188b2aa9d5a87113aaf1122/
DISTNAME=	server
EXTRACT_SUFX=	.jar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	freebsd@jonathanprice.org
COMMENT=	Dedicated server for the game Minecraft

LICENSE=	minecraft
LICENSE_NAME=	Minecraft End User License Agreement
LICENSE_TEXT=	The license can be viewed at: https://account.mojang.com/documents/minecraft_eula
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

USE_JAVA=	yes
JAVA_VERSION=	17

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	minecraft-server pkg-deinstall pkg-message
SUB_LIST=	VERSION=${PORTVERSION}

USERS=		mcserver
GROUPS=		${USERS}

PLIST_SUB=	VERSION=${PORTVERSION}

CONFIG_FILES=	banned-ips.json banned-players.json eula.txt ops.json \
		server.properties usercache.json whitelist.json

OPTIONS_DEFAULT=	STANDALONE
OPTIONS_SINGLE=		RUN
OPTIONS_SINGLE_RUN=	DAEMON STANDALONE
OPTIONS_SUB=		yes

DAEMON_DESC=		Run as a service
STANDALONE_DESC=	Run the .jar file directly
DAEMON_RUN_DEPENDS=	tmux:sysutils/tmux
DAEMON_VARS=		USE_RC_SUBR=minecraft

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} \
		${STAGEDIR}${PREFIX}/${PORTNAME}
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
	${INSTALL_SCRIPT} ${WRKDIR}/minecraft-server \
		${STAGEDIR}${PREFIX}/bin
	${CP} ${FILESDIR}/java-args.txt ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
