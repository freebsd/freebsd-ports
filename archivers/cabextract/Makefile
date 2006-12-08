# New ports collection makefile for:	cabextract
# Date Created:				30 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cabextract
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.kyz.uklinux.net/downloads/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	A program to extract Microsoft cabinet (.CAB) files

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes

MANLANG=	"" ja
MAN1=		cabextract.1
PORTDOCS=	magic wince_cab_format.html wince_info wince_rename \
		AUTHORS COPYING ChangeLog INSTALL NEWS README TODO
PLIST_FILES=	bin/cabextract

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ja/cabextract.1 ${MAN1PREFIX}/man/ja/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/magic ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/wince_cab_format.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/wince_info ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/wince_rename ${DOCSDIR}
.for i in AUTHORS COPYING ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
