# ex:ts=8
# Ports collection makefile for:  mixal
# Date created:			  21-Dec-1996
# Whom:                 	  David O'Brien <obrien@cs.ucdavis.edu>
#
# $FreeBSD$
#

PORTNAME=	mixal
PORTVERSION=	1.07
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/retro/ \
		http://dl.droso.net/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Assembler and interpreter for Donald Knuth's mythical MIX computer

ALL_TARGET=	# none

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mix ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for F in READ.ME MIX.DOC NOTES opcodes *.mix
	${INSTALL_DATA} ${WRKSRC}/${F} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
