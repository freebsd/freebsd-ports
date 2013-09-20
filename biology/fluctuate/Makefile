# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

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

NO_STAGE=	yes
do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/*.doc ${DOCSDIR}/
.endif

.include <bsd.port.mk>
