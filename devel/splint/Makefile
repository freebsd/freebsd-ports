# New ports collection makefile for:  lclint 
# Version required:	2.2a
# Date created: 	9 September 1996
# Whom:			moeding
#
# $Id: Makefile,v 1.1.1.1 1996/12/11 22:51:21 obrien Exp $
#

DISTNAME=	lclint-2.2a
CATEGORIES=	devel
MASTER_SITES=	ftp://larch.lcs.mit.edu/pub/Larch/lclint/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	moeding@bn.DeTeMobil.de

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

do-build:
	@(cd ${WRKSRC}; ${GMAKE})

post-install:
	@strip ${PREFIX}/bin/lclint

.include <bsd.port.mk>
