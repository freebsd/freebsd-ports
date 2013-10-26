# Created by: ache
# $FreeBSD$

PORTNAME=	arc
PORTVERSION=	5.21p
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Create & extract files from DOS .ARC files

LICENSE=	GPLv2

PLIST_FILES=	bin/arc bin/marc man/man1/arc.1.gz
PORTDOCS=	Arc521.doc

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arc ${WRKSRC}/marc\
		${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/arc.1 ${STAGEDIR}/${PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Arc521.doc ${STAGEDIR}/${DOCSDIR}
.endif

.include <bsd.port.post.mk>
