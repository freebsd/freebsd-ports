# New ports collection makefile for:   XFlame
# Version required:    1.1.1
# Date created:        2 January 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id$
#

DISTNAME=	xflame-1.1.1
CATEGORIES=	games
MASTER_SITES=	http://www.owlnet.rice.edu/~rahul/

MAINTAINER=	kkennawa@physics.adelaide.edu.au

USE_IMAKE=	yes

NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xflame ${PREFIX}/bin/xflame

.include <bsd.port.mk>
