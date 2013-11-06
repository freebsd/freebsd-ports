# Created by: johnh@isi.edu
# $FreeBSD$

PORTNAME=	dontspace
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	games tk
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A solitaire game for X11 modeled after Free Space

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games
CONFIGURE_ENV=	WISHX=${WISH}
USES+=		tk
MAN6=		dontspace.6

NO_STAGE=	yes
.include <bsd.port.mk>
