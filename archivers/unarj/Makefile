# Created by: ache
# $FreeBSD$

PORTNAME=	unarj
PORTVERSION=	2.65
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	https://aklv.github.io/distfiles/

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Allows files to be extracted from ARJ archives

USES=	tar:tgz

PLIST_FILES=	bin/unarj
PORTDOCS=	unarj.txt technote.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unarj ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
