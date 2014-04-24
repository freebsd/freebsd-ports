# Created by: Martin Kropfinger
# $FreeBSD$

PORTNAME=	minecraft-client
PORTVERSION=	1.7.9
CATEGORIES=	games java
MASTER_SITES=	http://s3.amazonaws.com/Minecraft.Download/launcher/:minecraft \
		http://media-mcw.cursecdn.com/c/c5/:icon
DISTFILES=	Minecraft.jar:minecraft \
		Grass.png:icon
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	janik@hikarihq.com
COMMENT=	Client for the block building game

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_OS=	native
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.7+
DESKTOP_ENTRIES="Minecraft" \
		"Block building game" \
		"${PREFIX}/share/pixmaps/minecraft-client.png" \
		"${PORTNAME}" \
		"Game;Java;" \
		false

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Minecraft.jar \
		${STAGEDIR}${DATADIR}/Minecraft.jar
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Grass.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/minecraft-client.png
	${SED}  -e 's|=JAVA_HOME|=${JAVA_HOME}|' \
		-e 's|PREFIX|${PREFIX}|' \
		-e 's|JAVA_CMD|${JAVA}|' ${FILESDIR}/minecraft-client \
		> ${WRKDIR}/minecraft-client
	${INSTALL_SCRIPT} ${WRKDIR}/minecraft-client ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
