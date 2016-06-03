# Created by: peter.thoenen@yahoo.com
# $FreeBSD$

PORTNAME=	ftjava
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	games java
MASTER_SITES=	http://www.warpfish.com/davisje/:file1 \
		http://home.roadrunner.com/~davisje/ftjava/:doc1
DISTFILES=	FTJavaV${PORTVERSION}.zip:file1 \
		FTJava_Documentation.html:doc1 faq.html:doc1 FTJava_Linux.html:doc1
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	FTJavaV${PORTVERSION}.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full Thrust PBEM Client

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	Images IncomingGames OutgoingGames Ships FTJava.jar \
		activation.jar imap.jar log4j-1.2.7.jar mail.jar \
		mailapi.jar png.jar pop3.jar skeetutil.jar smtp.jar xerces.jar \
		xercesImpl.jar xmlParserAPIs.jar

PLIST_FILES=	bin/ftjava
PORTDOCS=	FTJava_Linux.html faq.html FTJava_Documentation.html
PORTDATA=	*
PLIST_DIRS=	%%DATADIR%%/Ships/FullThrust/Kravak \
		%%DATADIR%%/Ships/EFSB/NonAligned \
		%%DATADIR%%/OutgoingGames \
		%%DATADIR%%/IncomingGames \
		%%DATADIR%%/Images/StarFleetWars/Terran \
		%%DATADIR%%/Images/StarFleetWars/Entomalian \
		%%DATADIR%%/Images/ShipIcons/StarFleetWars \
		%%DATADIR%%/Images/ShipIcons/FullThrust \
		%%DATADIR%%/Images/FullThrust/Sylvian \
		%%DATADIR%%/Images/FullThrust/Kali \
		%%DATADIR%%/Images/FullThrust/Eurasian

SUB_FILES=	ftjava.sh

DESKTOP_ENTRIES=	"FTJava" "A PBEM client for Full Thrust" \
			"${DATADIR}/Images/FTJava.ico" \
			"ftjava" "Game;BoardGame;StrategyGame;" \
			false

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} ";"
	cd ${WRKSRC} && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} ";"
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME:tl}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
