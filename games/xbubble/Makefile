# New ports collection makefile for:   xbubble
# Date created:        2002-11-03
# Whom:                Klaus Goger <klaus.goger@reflex.at>
#
# $FreeBSD$

PORTNAME=	xbubble
PORTVERSION=	0.5.8
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle Bobble clone for Unix/X11 platforms

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

MAN6=		xbubble.6

USE_XORG=	x11 xmu
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/libpng" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

.include <bsd.port.mk>
