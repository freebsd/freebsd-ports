# Created by: ijliao
# $FreeBSD$

PORTNAME=	dmachine
PORTVERSION=	0.24
CATEGORIES=	ftp java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Non interactive, non graphical, batch download manager

OPTIONS_DEFINE=	DOCS

USE_JAVA=	yes
NO_BUILD=	yes
SUB_FILES=	dmachine.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dmachine.sh ${STAGEDIR}${PREFIX}/bin/dmachine
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dmachine-${PORTVERSION}.jar ${STAGEDIR}${PREFIX}/share/java/classes/dmachine.jar
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dmachine.cnf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
