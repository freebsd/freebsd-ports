# New ports collection makefile for:   XFlame
# Version required:    1.1.1
# Date created:        2 January 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id: Makefile,v 1.1.1.1 1999/01/28 18:58:34 sada Exp $
#

DISTNAME=	xflame-1.1.1
CATEGORIES=	games
MASTER_SITES=	http://www.owlnet.rice.edu/~rahul/

MAINTAINER=	kris@FreeBSD.ORG

USE_IMAKE=	yes

NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xflame ${PREFIX}/bin/xflame

.include <bsd.port.mk>
