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
MASTER_SITES=	http://www.tuxedo.org/~esr/retro/ \
		http://dl.droso.net/ports/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=

DOCDIR=		${PREFIX}/share/doc/mix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mix ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/READ.ME ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/MIX.DOC ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/NOTES ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/opcodes ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.mix ${DOCDIR}
.endif

.include <bsd.port.mk>
