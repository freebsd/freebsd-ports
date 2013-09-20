# Created by: ache
# $FreeBSD$

PORTNAME=	arc
PORTVERSION=	5.21p
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Create & extract files from DOS .ARC files

NO_STAGE=	yes
PLIST_FILES=	bin/arc bin/marc
PORTDOCS=	Arc521.doc
MAN1=		arc.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arc ${WRKSRC}/marc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/arc.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Arc521.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
