# New ports collection makefile for:	xmms-infinity
# Date created:				14 Dec 2001
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-infinity
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://julien.carme.free.fr/
DISTNAME=	infinity-${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A XMMS plug-in which generate full-screen interactive light effects

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		SDL-1.1.5:${PORTSDIR}/devel/sdl12
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|g' ${WRKSRC}/*.[ch] \
		${WRKSRC}/configure

.include <bsd.port.mk>
