# New ports collection makefile for: sfbol
# Date created:                      06FEB11
# Whom:                              peter.thoenen@yahoo.com
#
# $FreeBSD$

PORTNAME=	sfbol
PORTVERSION=	4.37
CATEGORIES=	games java
MASTER_SITES=	http://www.sfbonline.com/programs/
DISTNAME=	install40
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	peter.thoenen@yahoo.com
COMMENT=	Star Fleet Battles Online

IGNOREFILES=	install40.jar
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_RUN=	jre
JAVA_EXTRACT=	jre
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	sfbol.sh

PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/${DISTFILES} \
		%%DATADIR%%/sfbicon.ico
PLIST_DIRS=	%%DATADIR%%

DESKTOP_ENTRIES=	"SFBOL" "Star Fleet Battles Online" \
			"${DATADIR}/sfbicon.ico" \
			"sfbol" "Application;Game;BoardGame;StrategyGame;" \
			false

RESTRICTED=	Commerical software.  Licenses does not allow redistribution.

FUDGE=		Users/paulfranz/sfbonline/SFBOL-Install/dist/core.jar

post-extract:
	@cd ${WRKDIR} && ${JAR} -xf ${DISTDIR}/${DISTFILES} ${FUDGE} 2>/dev/null | ${TRUE}
	@cd ${WRKDIR} && ${JAR} -xf ${FUDGE} sfbicon.ico

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/sfbicon.ico ${DATADIR}
	@${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME:L}

.include <bsd.port.mk>
