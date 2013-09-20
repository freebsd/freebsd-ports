# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bombermaze
PORTVERSION=	0.6.6
PORTREVISION=	11
CATEGORIES=	games gnome
MASTER_SITES=	SF

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A multiplayer game, strategy place bombs to kill enemies and obstacles

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf
USES=		gettext
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CFLAGS+=	-fpermissive

NO_STAGE=	yes
.include <bsd.port.mk>
