# New ports collection makefile for:	ficl
# Date created:		23 August 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	ficl
PORTVERSION=	4.0.31
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-all/${PORTNAME}${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Forth Inspired Command Language

NO_WRKSUBDIR=	defined
NOMAN=		defined

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes

ALL_TARGET=	everything

DOCS=	releases.html parsesteps.html oop.html locals.html links.html \
	license.html index.html api.html ficl.html favicon.ico dpans.html \
	debugger.html upgrading.html

DOCS_ARTICLES=	sigplan9906.doc oo_in_c.html jwsforml.pdf ficlddj.pdf
DOCS_GRAPHICS=	sourceforge.jpg ficl_top.jpg ficl_oop.jpg ficl.4.96.jpg \
		ficl.4.64.jpg ficl.4.128.jpg 4ring.gif
DOCS_SOURCE=	upgrading.ht releases.ht parsesteps.ht oop.ht locals.ht \
		links.ht license.ht index.ht generate.py ficl.ht dpans.ht \
		debugger.ht api.ht

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ficl ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/libficl.so.4 ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libficl.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/source ${DOCSDIR}/articles ${DOCSDIR}/graphics
.for doc in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/${doc} ${DOCSDIR}
.endfor
.for doc in ${DOCS_ARTICLES}
	${INSTALL_MAN} ${WRKSRC}/doc/articles/${doc} ${DOCSDIR}/articles
.endfor
.for doc in ${DOCS_GRAPHICS}
	${INSTALL_MAN} ${WRKSRC}/doc/graphics/${doc} ${DOCSDIR}/graphics
.endfor
.for doc in ${DOCS_SOURCE}
	${INSTALL_MAN} ${WRKSRC}/doc/source/${doc} ${DOCSDIR}/source
.endfor
.endif

.include <bsd.port.mk>
