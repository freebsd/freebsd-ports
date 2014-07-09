# Created by: johnh@isi.edu
# $FreeBSD$

PORTNAME=	klondike
PORTVERSION=	1.9
PORTREVISION=	3
CATEGORIES=	games tk
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=	faber@isi.edu
COMMENT=	Solitaire game for X11

USES=		tk:run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games
CONFIGURE_ENV=	WISHX=${WISH}

.include <bsd.port.mk>
