# New ports collection makefile for:	cabextract
# Date Created:				30 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cabextract
PORTVERSION=	1.3
CATEGORIES=	archivers
MASTER_SITES=	http://www.cabextract.org.uk/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	A program to extract Microsoft cabinet (.CAB) files

GNU_CONFIGURE=	yes

MANLANG=	"" ja
MAN1=		cabextract.1

PLIST_FILES=	bin/cabextract
DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README TODO
DOC_DOCS=	magic wince_cab_format.html
SRC_DOCS=	wince_info wince_rename
PORTDOCS=	${DOCS} ${DOC_DOCS} ${SRC_DOCS}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/cabextract.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/ja/cabextract.1 ${MAN1PREFIX}/man/ja/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in ${DOC_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.for i in ${SRC_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/src/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
