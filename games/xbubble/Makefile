# Created by: Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	xbubble
PORTVERSION=	0.5.8
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle Bobble clone for Unix/X11 platforms

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

MAN6=		xbubble.6

USE_XORG=	x11 xmu
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		gettext

CPPFLAGS+=	-I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

NO_STAGE=	yes
.include <bsd.port.mk>
