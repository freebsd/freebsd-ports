# New ports collection makefile for:    vile
# Version required:     5.2
# Date created:         Thu Feb 23, 1995
# Whom:                 pgf
#
# $Id: Makefile,v 1.4 1995/04/09 06:11:14 asami Exp $
#

DISTNAME=       vile-5.2
CATEGORIES+=	editors
MASTER_SITES=   ftp://id.wing.net/pub/pgf/vile/

MAKEFILE=	makefile
GNU_CONFIGURE=	yes

post-install:
	gzip -9nf ${PREFIX}/man/man1/vile.1

.include <bsd.port.mk>
