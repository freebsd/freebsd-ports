PORTNAME=	recombine
PORTVERSION=	1.41
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	https://lamarcweb.github.io/lamarcweb/recombine/
DISTNAME=	${PORTNAME}${PORTVERSION}.src.doc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to fit population models across sites
WWW=		https://lamarcweb.github.io/lamarcweb/recombine/

DEPRECATED=	Upstream advises to use biology/lamarc
EXPIRATION_DATE=	2024-01-17

USES=		shebangfix

SHEBANG_FILES=	filetran

ALL_TARGET=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

PLIST_FILES+=	bin/filetran bin/recombine
PORTDOCS=	recombine.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/filetran ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/recombine.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
