# New ports collection makefile for:    dontspace
# Version required:     1.2
# Date created:         26-Apr-97
# Whom:                 johnh@isi.edu
#
# $FreeBSD$
#

DISTNAME=       dontspace-1.2
CATEGORIES=     games tk82
MASTER_SITES=   http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=     johnh@isi.edu

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=  Yes
CONFIGURE_ARGS= --bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games \
		--mandir=${PREFIX}/man
CONFIGURE_ENV=  WISHX=${PREFIX}/bin/wish8.2
MAN6=           dontspace.6

.include <bsd.port.mk>
