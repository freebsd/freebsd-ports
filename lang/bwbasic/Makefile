# New ports collection makefile for:	bwbasic
# Version required:	2.10
# Date created:		9 Aug 1995
# Whom:			msmith@atrad.adelaide.edu.au
#
# $Id: Makefile,v 1.3 1995/11/22 13:12:28 asami Exp $
#

DISTNAME=	bwbasic-2.10
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.eng.umd.edu/pub/basic/

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
