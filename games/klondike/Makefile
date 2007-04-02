# New ports collection makefile for:    klondike
# Date created:         26-Apr-97
# Whom:                 johnh@isi.edu
#
# $FreeBSD$
#

PORTNAME=	klondike
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	games tk84
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=	faber@isi.edu
COMMENT=	A solitaire game for X11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games \
		--mandir=${PREFIX}/man
USE_TK_RUN=	yes
MAN6=		klondike.6

.include <bsd.port.pre.mk>

CONFIGURE_ENV=	WISHX=${WISH}

.include <bsd.port.post.mk>
