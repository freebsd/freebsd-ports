# New ports collection makefile for:  lclint 
# Version required:	2.2a
# Date created: 	9 September 1996
# Whom:			moeding
#
# $Id: porting.sgml,v 1.2.4.5 1996/06/19 20:28:08 jkh Exp $
#

DISTNAME=	lclint-2.2a.src
PKGNAME=	lclint-2.2a
CATEGORIES=	devel
MASTER_SITES=	ftp://larch.lcs.mit.edu/pub/Larch/lclint/

MAINTAINER=	moeding@bn.DeTeMobil.de

WRKSRC=		${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

do-build:
	@(cd ${WRKSRC}; ${GMAKE})

post-install:
	@strip ${PREFIX}/bin/lclint

.include <bsd.port.mk>
