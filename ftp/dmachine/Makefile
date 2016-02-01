# Created by: ijliao
# $FreeBSD$

PORTNAME=	dmachine
PORTVERSION=	0.24
CATEGORIES=	ftp java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Non interactive, non graphical, batch download manager

LICENSE=	GPLv2

USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	dmachine.sh

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dmachine.sh ${STAGEDIR}${PREFIX}/bin/dmachine
	${INSTALL_DATA} ${WRKSRC}/dmachine-${PORTVERSION}.jar ${STAGEDIR}${PREFIX}/share/java/classes/dmachine.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dmachine.cnf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
