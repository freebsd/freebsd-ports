# New ports collection makefile for:  lclint
# Version required:	2.4b
# Date created: 	9 September 1996
# Whom:			moeding
#
# $Id: Makefile,v 1.4 1999/06/25 04:02:23 billf Exp $
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
