# New ports collection makefile for:    xvile
# Version required:     6.0
# Date created:         Fri Jun 21, 1996
# Whom:                 pgf
#
# $Id: Makefile,v 1.5 1995/04/24 03:38:30 asami Exp $
#

DISTNAME=       vile-6.0
PKGNAME=	xvile-6.0
CATEGORIES+=	editors
MASTER_SITES=   ftp://id.wing.net/pub/pgf/vile/

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-screen=x11

post-install:
	gzip -9nf ${PREFIX}/man/man1/xvile.1

.include <bsd.port.mk>
