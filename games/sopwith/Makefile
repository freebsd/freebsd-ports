# New ports collection makefile for:	sopwith
# Date created:			1 July 2002
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	sopwith
PORTVERSION=	1.7.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sdl-sopwith
DISTNAME=	sdl_${PORTNAME}-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	A classic WW1 biplane game

BUILD_DEPENDS=	${LOCALBASE}/bin/sdl11-config:${PORTSDIR}/devel/sdl12

USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG=${LOCALBASE}/bin/sdl11-config

MAN6=		sopwith.6

.include <bsd.port.mk>
