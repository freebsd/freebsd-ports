# New ports collection makefile for:    klondike
# Version required:     1.8
# Date created:         26-Apr-97
# Whom:                 johnh@isi.edu
#
# $Id: Makefile,v 1.5 1998/02/21 22:38:01 fenner Exp $
#

DISTNAME=       klondike-1.8
CATEGORIES=     games tk41
MASTER_SITES=   http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=     johnh@isi.edu

RUN_DEPENDS=    wish4.1:${PORTSDIR}/x11-toolkits/tk41

GNU_CONFIGURE=  Yes
CONFIGURE_ARGS= --bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games \
		--mandir=${PREFIX}/man
CONFIGURE_ENV=  WISHX=${PREFIX}/bin/wish4.1
MAN6=           klondike.6

.include <bsd.port.mk>
