# New ports collection makefile for:    klondike
# Version required:     1.8
# Date created:         26-Apr-97
# Whom:                 johnh@isi.edu
#
# $Id: Makefile,v 1.1.1.1 1997/05/07 07:41:50 tg Exp $
#

DISTNAME=       klondike-1.8
CATEGORIES=     games
MASTER_SITES=   http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=     johnh@isi.edu

RUN_DEPENDS=    wish4.1:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=  Yes
CONFIGURE_ARGS= --bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games \
		--mandir=${PREFIX}/man
MAN6=           klondike.6

.include <bsd.port.mk>
