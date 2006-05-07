# New ports collection makefile for:   senken
# Date created:        15 January 2003
# Whom:                tmartin@andrew.cmu.edu
#
# $FreeBSD$

PORTNAME=	senken
PORTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	jmelo@FreeBSD.org
COMMENT=	A city simulation game

USE_GNOME=	gnometarget gtk20
USE_SDL=	image sdl
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/X11R6/include||g  ; \
		 s|-L/usr/X11R6/lib||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/install-sh -d/d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
