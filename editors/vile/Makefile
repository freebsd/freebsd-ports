# New ports collection makefile for:    vile
# Version required:     7.3
# Date created:         Wed Nov 26, 1996
# Whom:                 pgf
#
# $Id: Makefile,v 1.13 1997/09/06 19:55:09 gj Exp $
#

DISTNAME=	vile-7.3
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://id.wing.net/pub/pgf/vile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gj@freebsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
MAN1=		vile.1

post-install:
	@echo "You might want to copy the *.rc files from the source tree before"
	@echo "doing \`make clean'."

.include <bsd.port.mk>
