# Created by: ijliao
# $FreeBSD$

PORTNAME=	dmachine
PORTVERSION=	0.24
CATEGORIES=	ftp java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A non interactive, non graphical, batch download manager

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
NO_BUILD=	yes
SUB_FILES=	dmachine.sh

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dmachine.sh ${PREFIX}/bin/dmachine
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dmachine-${PORTVERSION}.jar ${PREFIX}/share/java/classes/dmachine.jar
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dmachine.cnf ${DOCSDIR}
.endif

.include <bsd.port.mk>
