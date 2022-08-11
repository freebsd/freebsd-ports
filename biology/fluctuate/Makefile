PORTNAME=	fluctuate
PORTVERSION=	1.40
CATEGORIES=	biology
MASTER_SITES=	http://evolution.gs.washington.edu/lamarc/fluctuate/
DISTNAME=	${PORTNAME}1.4.src.doc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to fit population models

WRKSRC=		${WRKDIR}/${PORTNAME}1.4
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/fluctuate
PORTDOCS=	errors.doc fluctuate.doc

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.doc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
