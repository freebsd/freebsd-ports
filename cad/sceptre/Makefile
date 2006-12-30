# New ports collection makefile for:	sceptre
# Date created:		11 February 2001
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	sceptre
PORTVERSION=	00.317
CATEGORIES=	cad
MASTER_SITES=	http://ftp.osuosl.org/pub/FreeBSD/distfiles/

MAINTAINER=	grog@FreeBSD.org
COMMENT=	SCEPTRE is a general purpose circuit analysis program

WITH_FORTRAN=	yes

NO_WRKSUBDIR=	YES

post-install:
.if !defined(NOPORTDOCS)
	  ${MKDIR} ${PREFIX}/share/doc/sceptre
	  ${INSTALL_DATA} ${WRKSRC}/doc/doc_en.pdf ${PREFIX}/share/doc/sceptre/doc_en.pdf
	  ${INSTALL_DATA} ${WRKSRC}/doc/doc_ger.pdf ${PREFIX}/share/doc/sceptre/doc_ger.pdf
.endif

.include <bsd.port.mk>
