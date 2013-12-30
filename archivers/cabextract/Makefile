# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cabextract
PORTVERSION=	1.4
CATEGORIES=	archivers
MASTER_SITES=	http://www.cabextract.org.uk/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Program to extract Microsoft cabinet (.CAB) files

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/cabextract \
		man/ja/man1/cabextract.1.gz \
		man/man1/cabextract.1.gz
DOCS=		AUTHORS ChangeLog NEWS README TODO
DOC_DOCS=	magic wince_cab_format.html
SRC_DOCS=	wince_info wince_rename
PORTDOCS=	${DOCS} ${DOC_DOCS} ${SRC_DOCS}

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/cabextract.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/ja/cabextract.1 ${STAGEDIR}${MAN1PREFIX}/man/ja/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in ${DOC_DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in ${SRC_DOCS}
	${INSTALL_DATA} ${WRKSRC}/src/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
