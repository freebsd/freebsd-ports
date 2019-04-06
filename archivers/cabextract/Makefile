# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cabextract
PORTVERSION=	1.9.1
CATEGORIES=	archivers
MASTER_SITES=	https://www.cabextract.org.uk/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Program to extract Microsoft cabinet (.CAB) files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe iconv

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/cabextract \
		man/ja/man1/cabextract.1.gz \
		man/man1/cabextract.1.gz
PORTDOCS=	${DOCS:T}

DOCS=		AUTHORS ChangeLog NEWS README TODO \
		doc/magic doc/wince_cab_format.html \
		src/wince_info src/wince_rename

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/cabextract.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/ja/cabextract.1 ${STAGEDIR}${MAN1PREFIX}/man/ja/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
