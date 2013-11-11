# Created by: tmartin@andrew.cmu.edu
# $FreeBSD$

PORTNAME=	senken
PORTVERSION=	0.3.0
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	City simulation game

USES=		pkgconfig
USE_GNOME=	gtk20
USE_SDL=	image sdl
GNU_CONFIGURE=	yes
LDFLAGS+=	-lm

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/X11R6/include||g  ; \
		 s|-L/usr/X11R6/lib||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/install-sh -d/d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
