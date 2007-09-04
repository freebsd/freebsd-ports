# New ports collection makefile for:	sceptre
# Date created:		11 February 2001
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	sceptre
PORTVERSION=	00.317
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://ftp.osuosl.org/pub/FreeBSD/distfiles/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SCEPTRE is a general purpose circuit analysis program

.include <bsd.port.pre.mk>

USE_FORTRAN=	g77
FFLAGS+=	-fno-automatic -O
.if ${ARCH} == "sparc64"
BROKEN=		Internal compiler error
.endif

NO_WRKSUBDIR=	YES

post-install:
.if !defined(NOPORTDOCS)
	  ${MKDIR} ${PREFIX}/share/doc/sceptre
	  ${INSTALL_DATA} ${WRKSRC}/doc/doc_en.pdf ${PREFIX}/share/doc/sceptre/doc_en.pdf
	  ${INSTALL_DATA} ${WRKSRC}/doc/doc_ger.pdf ${PREFIX}/share/doc/sceptre/doc_ger.pdf
.endif

.include <bsd.port.post.mk>
