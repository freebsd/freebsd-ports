# New ports collection makefile for:	bwbasic
# Version required:	2.10
# Date created:		9 Aug 1995
# Whom:			msmith@atrad.adelaide.edu.au
#
# $Id: Makefile,v 1.4 1996/11/12 02:18:04 obrien Exp $
#

DISTNAME=	bwbasic-2.10
CATEGORIES=	lang
MASTER_SITES=	ftp://locke.ccil.org/pub/retro/bwbasic-2.10.tar.gz

MAINTAINER=	msmith@atrad.adelaide.edu.au

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

# This puts the documentation in ${PREFIX}/share/bwbasic, and the 
# test programs in ${PREFIX}/share/bwbasic/bwbtest.

post-install:
	-${MKDIR} ${PREFIX}/share/bwbasic
	${CP} ${WRKSRC}/bwbasic.doc ${PREFIX}/share/bwbasic/
	${CP} -r ${WRKSRC}/bwbtest ${PREFIX}/share/bwbasic/

.include <bsd.port.mk>
