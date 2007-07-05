# New ports collection makefile for:    dontspace
# Date created:         26-Apr-97
# Whom:                 johnh@isi.edu
#
# $FreeBSD$
#

PORTNAME=	dontspace
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games tk84
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A solitaire game for X11 modeled after Free Space

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games \
		--mandir=${PREFIX}/man
CONFIGURE_ENV=	WISHX=${PREFIX}/bin/wish8.4
USE_TK=		yes
MAN6=		dontspace.6

.include <bsd.port.mk>
