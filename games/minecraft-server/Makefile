PORTNAME=	minecraft-server
DISTVERSION=	1.21.10
CATEGORIES=	games java
MASTER_SITES=	https://piston-data.mojang.com/v1/objects/95495a7f485eedd84ce928cef5e223b757d2f764/
DISTNAME=	server
EXTRACT_SUFX=	.jar
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=

MAINTAINER=	freebsd@jonathanprice.org
COMMENT=	Dedicated server for the game Minecraft
WWW=		http://www.minecraft.net/

LICENSE=	minecraft
LICENSE_NAME=	Minecraft End User License Agreement
LICENSE_TEXT=	The license can be viewed at: https://account.mojang.com/documents/minecraft_eula
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

USES=		java
JAVA_VERSION=	21

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	minecraft-server pkg-deinstall pkg-message
SUB_LIST=	JAVA_VERSION=${JAVA_VERSION} VERSION=${DISTVERSION}

USERS=		mcserver
GROUPS=		${USERS}

PLIST_SUB=	VERSION=${DISTVERSION}

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
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME} \
		 ${STAGEDIR}${ETCDIR} \
		 ${STAGEDIR}/var/db/minecraft-server \
		 ${STAGEDIR}/var/log/minecraft-server/debug
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} \
		${STAGEDIR}${PREFIX}/${PORTNAME}
.for file in ${CONFIG_FILES}
	${LN} -s ${ETCDIR}/${file} ${STAGEDIR}${PREFIX}/${PORTNAME}/${file}
.endfor
	${LN} -sf /var/db/minecraft-server ${STAGEDIR}${PREFIX}/${PORTNAME}/world
	${LN} -sf /var/log/minecraft-server ${STAGEDIR}${PREFIX}/${PORTNAME}/logs
	${LN} -sf /var/log/minecraft-server/debug ${STAGEDIR}${PREFIX}/${PORTNAME}/debug

post-install-STANDALONE-on:
	${INSTALL_SCRIPT} ${WRKDIR}/minecraft-server \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/java-args.txt ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
