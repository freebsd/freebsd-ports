# New ports collection makefile for:    xvile
# Version required:     5.2
# Date created:         Tue Feb 21, 1995
# Whom:                 pgf
#
# $Id: Makefile,v 1.4 1995/04/09 06:11:17 asami Exp $
#

DISTNAME=       vile-5.2
PKGNAME=	xvile-5.2
CATEGORIES+=	editors
MASTER_SITES=   ftp://id.wing.net/pub/pgf/vile/

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-screen=x11

post-install:
	gzip -9nf ${PREFIX}/man/man1/xvile.1

.include <bsd.port.mk>
