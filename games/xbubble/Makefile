# New ports collection makefile for:   xbubble
# Date created:        2002-11-03
# Whom:                Klaus Goger <klaus.goger@reflex.at>
#
# $FreeBSD$

PORTNAME=	xbubble
PORTVERSION=	0.5.8
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.gnu.org/pub/savannah/files/xbubble/

MAINTAINER=	klaus.goger@reflex.at
COMMENT=	Puzzle Bobble clone for Unix/X11 platforms

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

MAN6=		xbubble.6

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/libpng" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

.include <bsd.port.mk>
