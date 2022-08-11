PORTNAME=	runelite
PORTVERSION=	2.2.0
CATEGORIES=	games java
MASTER_SITES+=	https://github.com/runelite/launcher/releases/download/${PORTVERSION}/:game \
		https://raw.githubusercontent.com/runelite/launcher/${PORTVERSION}/appimage/:icon \
		https://raw.githubusercontent.com/runelite/launcher/${PORTVERSION}/:license
DISTFILES=	RuneLite.jar:game \
		runelite.png:icon \
		LICENSE:license
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Open source Old School RuneScape client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		cpe
USE_JAVA=	yes
JAVA_VERSION=	11

DESKTOP_ENTRIES="RuneLite" \
		"Old School RuneScape client" \
		"${PREFIX}/share/pixmaps/runelite.png" \
		"${PORTNAME}" \
		"Game;Java;" \
		false

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/RuneLite.jar \
		${STAGEDIR}${DATADIR}/RuneLite.jar
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/runelite.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/runelite.png
	${ECHO} "exec ${JAVA} -jar ${DATADIR}/RuneLite.jar" >> ${WRKDIR}/runelite
	${INSTALL_SCRIPT} ${WRKDIR}/runelite ${STAGEDIR}${PREFIX}/bin

PLIST_FILES=	bin/runelite \
		share/pixmaps/runelite.png \
		share/runelite/RuneLite.jar

.include <bsd.port.mk>
