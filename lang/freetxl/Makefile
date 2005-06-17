# New ports collection makefile for: freetxl
# Date created:	    25 April 2003
# Whom:		    Ryan Thompson <ryan@sasknow.com>
#
# $FreeBSD$
#

PORTNAME=	freetxl
PORTVERSION=	10.3
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.sasknow.com/pub/txl/
DISTNAME=	txl${PORTVERSION}.linux

MAINTAINER=	ryan@sasknow.com
COMMENT=	The TXL Programming Language (transformation by example)

USE_LINUX=	yes

MAN1=		txl.1 txlc.1 txldb.1 txlp.1

PORTDOCS=	00README.txt COPYRIGHT.txt Documents.html Examples.html \
		FILES.txt Learning.html Support.html

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bin/txl \
                ${WRKSRC}/bin/txldb

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/bin/txl \
		${WRKSRC}/bin/txlc \
		${WRKSRC}/bin/txldb \
		${WRKSRC}/bin/txlp \
		${PREFIX}/bin
	${INSTALL_DATA} \
		${WRKSRC}/lib/txlapr.x \
		${WRKSRC}/lib/txlcvt.x \
		${WRKSRC}/lib/txlmain.o \
		${WRKSRC}/lib/txlpf.x \
		${WRKSRC}/lib/txlvm.o \
		${PREFIX}/lib
.if !defined(NO_INSTALL_MANPAGES)
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${file} ${PREFIX}/man/man1/
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
