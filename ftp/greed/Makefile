# New ports collection makefile for: 	greed
# Version required:	0.652
# Date created:		13 April 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=     	greed
PKGNAME=	greed-0.652
CATEGORIES=	net
MASTER_SITES=	http://www.public.asu.edu/~arturner/

MAINTAINER=	cpiazza@home.net

MAN1=	greed.1

ALL_TARGET=	freebsd

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/greed.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/greed.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
