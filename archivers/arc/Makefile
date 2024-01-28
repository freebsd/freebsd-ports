PORTNAME=	arc
PORTVERSION=	5.21q
PORTREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Create & extract files from DOS .ARC files
WWW=		https://arc.sourceforge.net/

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	ani6al
GH_PROJECT=	arc

CONFLICTS_INSTALL= arcanist-php[0-9][0-9]

OPTIONS_DEFINE=	DOCS

USES=		alias cpe
CPE_VENDOR=	arc_project
PLIST_FILES=	bin/arc bin/marc share/man/man1/arc.1.gz
PORTDOCS=	Arc521.doc

post-patch:
.for f in arc.1 marc.1
	@${REINPLACE_CMD} 's/ 1L / 1 /' ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arc ${WRKSRC}/marc\
		${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/arc.1 ${STAGEDIR}/${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Arc521.doc ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
