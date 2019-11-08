# Created by: tmartin@andrew.cmu.edu
# $FreeBSD$

PORTNAME=	senken
PORTVERSION=	0.3.0
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	City simulation game

USES=		gnome pkgconfig sdl
USE_GNOME=	gtk20
USE_SDL=	image sdl
GNU_CONFIGURE=	yes
LDFLAGS+=	-lm

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/X11R6/include||g  ; \
		 s|-L/usr/X11R6/lib||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/install-sh -d/d' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
