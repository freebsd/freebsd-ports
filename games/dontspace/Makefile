# Created by: johnh@isi.edu
# $FreeBSD$

PORTNAME=	dontspace
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	games tk
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Solitaire game for X11 modeled after Free Space

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games
CONFIGURE_ENV=	WISHX=${WISH}
USES+=		tk

post-patch:
	@${REINPLACE_CMD} -E 's,(BIN|LIB|MAN)DIR),DESTDIR)$$(&,g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
