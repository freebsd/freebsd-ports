# Created by: ache
# $FreeBSD$

PORTNAME=	unarj
PORTVERSION=	2.65
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	ak-various-projects
EXTRACT_SUFX=	.tgz

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Allows files to be extracted from ARJ archives

PLIST_FILES=	bin/unarj
PORTDOCS=	unarj.txt technote.txt

post-patch:
	${CP} ${FILESDIR}/sanitize.c ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unarj ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
