# New ports collection makefile for:    dontspace
# Date created:         26-Apr-97
# Whom:                 johnh@isi.edu
#
# $FreeBSD$
#

PORTNAME=	dontspace
PORTVERSION=	1.2
CATEGORIES=	games tk82
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=	johnh@isi.edu
COMMENT=	A solitaire game for X11 modeled after Free Space

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games \
		--mandir=${PREFIX}/man
CONFIGURE_ENV=	WISHX=${PREFIX}/bin/wish8.2
MAN6=		dontspace.6

.include <bsd.port.mk>
