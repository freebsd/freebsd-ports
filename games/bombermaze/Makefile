# New ports collection makefile for:	bombermaze
# Date created:				25 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bombermaze
PORTVERSION=	0.6.6
PORTREVISION=	10
CATEGORIES=	games gnome
MASTER_SITES=	SF

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A multiplayer game, strategy place bombs to kill enemies and obstacles

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CFLAGS+=	-fpermissive

.include <bsd.port.mk>
