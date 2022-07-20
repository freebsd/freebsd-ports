PORTNAME=	recombine
PORTVERSION=	1.41
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://evolution.gs.washington.edu/lamarc/recombine/
DISTNAME=	${PORTNAME}${PORTVERSION}.src.doc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to fit population models across sites

USES=		shebangfix

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

ALL_TARGET=	${PORTNAME}

PLIST_FILES+=	bin/filetran bin/recombine
PORTDOCS=	recombine.txt
SHEBANG_FILES=	filetran

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/filetran ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/recombine.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
