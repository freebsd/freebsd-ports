# New ports collection makefile for:    xvile
# Version required:     6.1
# Date created:         Fri Jun 21, 1996
# Whom:                 pgf
#
# $Id: Makefile,v 1.6 1996/06/25 03:47:35 gpalmer Exp $
#

DISTNAME=       vile-6.1
PKGNAME=	xvile-6.1
CATEGORIES+=	editors
MASTER_SITES=   ftp://id.wing.net/pub/pgf/vile/

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-screen=x11

post-install:
	.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/xvile.1
.endif

.include <bsd.port.mk>
