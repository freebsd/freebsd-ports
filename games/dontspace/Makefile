# New ports collection makefile for:    dontspace
# Version required:     1.2
# Date created:         26-Apr-97
# Whom:                 johnh@isi.edu
#
# $Id: Makefile,v 1.1.1.1 1997/05/07 07:44:38 tg Exp $
#

DISTNAME=       dontspace-1.2
CATEGORIES=     games
MASTER_SITES=   http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=     johnh@isi.edu

RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=  Yes
CONFIGURE_ARGS= --bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games \
		--mandir=${PREFIX}/man
CONFIGURE_ENV+= WISHX=${PREFIX}/bin/wish4.1
MAN6=           dontspace.6

.include <bsd.port.mk>
