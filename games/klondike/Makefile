# New ports collection makefile for:    klondike
# Version required:     1.8
# Date created:         26-Apr-97
# Whom:                 johnh@isi.edu
#
# $Id: Makefile,v 1.6 1998/08/07 23:56:20 asami Exp $
#

DISTNAME=       klondike-1.9
CATEGORIES=     games tk42
MASTER_SITES=   http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=     faber@isi.edu

RUN_DEPENDS=    wish4.2:${PORTSDIR}/x11-toolkits/tk42

GNU_CONFIGURE=  Yes
CONFIGURE_ARGS= --bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games \
		--mandir=${PREFIX}/man
CONFIGURE_ENV=  WISHX=${PREFIX}/bin/wish4.2
MAN6=           klondike.6

.include <bsd.port.mk>
