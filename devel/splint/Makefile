# New ports collection makefile for:  lclint
# Version required:	2.4b
# Date created: 	9 September 1996
# Whom:			moeding
#
# $Id: Makefile,v 1.2 1996/12/12 05:21:36 asami Exp $
#

DISTNAME=	lclint-2.4b
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.sds.lcs.mit.edu/pub/lclint/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	s.moeding@ndh.net

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

do-build:
	@(cd ${WRKSRC}; ${GMAKE})

post-install:
	@strip ${PREFIX}/bin/lclint

.include <bsd.port.mk>
