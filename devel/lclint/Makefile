# New ports collection makefile for:  lclint
# Version required:	2.4b
# Date created: 	9 September 1996
# Whom:			moeding
#
# $Id: Makefile,v 1.3 1998/07/03 23:36:18 steve Exp $
#

DISTNAME=	lclint-2.4b
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.sds.lcs.mit.edu/pub/lclint/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	s.moeding@ndh.net

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
NO_PACKAGE=	"doesn't respect $CFLAGS"

do-build:
	@(cd ${WRKSRC}; ${GMAKE})

post-install:
	@strip ${PREFIX}/bin/lclint

.include <bsd.port.mk>
