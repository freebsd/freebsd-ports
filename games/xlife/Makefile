# New ports collection makefile for:    xlife
# Version required:     3.0
# Date created:         15 March 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.4 1995/04/11 00:20:39 asami Exp $
#

DISTNAME=       xlife
PKGNAME=	xlife-3.0
CATEGORIES=	games
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/X11/R5-contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=      yes

pre-install:
	@(cd ${WRKSRC}; make install.patterns)

.include <bsd.port.mk>
