# New ports collection makefile for:    vile
# Version required:     6.1
# Date created:         Fri Jun 21, 1996
# Whom:                 pgf
#
# $Id: Makefile,v 1.7 1996/10/01 02:33:39 gpalmer Exp $
#

DISTNAME=       vile-6.1
CATEGORIES+=	editors
MASTER_SITES=   ftp://id.wing.net/pub/pgf/vile/

MAKEFILE=	makefile
GNU_CONFIGURE=	yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/vile.1
.endif

.include <bsd.port.mk>
