# New ports collection makefile for:	micq
# Version required:			11 Oct 1998
# Date created:				31 Oct 1998
# Whom:					Seiichirou Hiraoka
#
# $Id$
#

DISTNAME=	micq
PKGNAME=	ja-micq-981011
CATEGORIES=	japanese net
MASTER_SITES=	ftp://micq.ml.org/pub/micq/Oct-11-98/
EXTRACT_SUFX=	.tgz

MAINTAINER=	flathill@FreeBSD.ORG

WRKSRC=		${WRKDIR}/micq981011

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
.for file in README TODO WISHLIST commands.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/micq
.endfor
.endif

.include <bsd.port.mk>
