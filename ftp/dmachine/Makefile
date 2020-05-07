# Created by: ijliao
# $FreeBSD$

PORTNAME=	dmachine
PORTVERSION=	0.25
CATEGORIES=	ftp java
MASTER_SITES=	SF

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Non interactive, non graphical, batch download manager

LICENSE=	GPLv2

USES=		zip
USE_JAVA=	yes

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	dmachine.sh

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dmachine.sh ${STAGEDIR}${PREFIX}/bin/dmachine
	${INSTALL_DATA} ${WRKSRC}/dmachine.jar ${STAGEDIR}${PREFIX}/share/java/classes/dmachine.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dmachine.cnf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
