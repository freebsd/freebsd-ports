# Created by: ache

PORTNAME=	arc
PORTVERSION=	5.21p
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Create & extract files from DOS .ARC files

LICENSE=	GPLv2

CONFLICTS=	php5-arcanist

OPTIONS_DEFINE=	DOCS

USES=		alias cpe
CPE_VENDOR=	arc_project
PLIST_FILES=	bin/arc bin/marc man/man1/arc.1.gz
PORTDOCS=	Arc521.doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arc ${WRKSRC}/marc\
		${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/arc.1 ${STAGEDIR}/${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Arc521.doc ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
