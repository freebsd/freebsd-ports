# New ports collection makefile for:    klondike
# Date created:         26-Apr-97
# Whom:                 johnh@isi.edu
#
# $FreeBSD$
#

PORTNAME=	klondike
PORTVERSION=	1.9
CATEGORIES=	games tk82
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=	faber@isi.edu
COMMENT=	A solitaire game for X11

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games \
		--mandir=${PREFIX}/man
CONFIGURE_ENV=	WISHX=${PREFIX}/bin/wish8.2
MAN6=		klondike.6

.include <bsd.port.mk>
