# Created by: peter.thoenen@yahoo.com
# $FreeBSD$

PORTNAME=	ftjava
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	games java
MASTER_SITES=	http://www.warpfish.com/davisje/:file1 \
		http://home.roadrunner.com/~davisje/ftjava/:doc1
DISTFILES=	FTJavaV${PORTVERSION}.zip:file1 \
		FTJava_Documentation.html:doc1 faq.html:doc1 FTJava_Linux.html:doc1
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	FTJavaV${PORTVERSION}.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full Thrust PBEM Client

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

IGNOREFILES=	FTJava_Documentation.html faq.html FTJava_Linux.html

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	Images IncomingGames OutgoingGames Ships FTJava.jar \
		activation.jar imap.jar log4j-1.2.7.jar mail.jar \
		mailapi.jar png.jar pop3.jar skeetutil.jar smtp.jar xerces.jar \
		xercesImpl.jar xmlParserAPIs.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	FTJava_Linux.html faq.html FTJava_Documentation.html
.endif

SUB_FILES=	ftjava.sh

DESKTOP_ENTRIES=	"FTJava" "A PBEM client for Full Thrust" \
			"${DATADIR}/Images/FTJava.ico" \
			"ftjava" "Game;BoardGame;StrategyGame;" \
			false

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} ";"
	cd ${WRKSRC} && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} ";"
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME:L}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
