# New ports collection makefile for:   xbubble
# Date created:        2002-11-03
# Whom:                Klaus Goger <klaus.goger@reflex.at>
#
# $FreeBSD$

PORTNAME=		xbubble
PORTVERSION=		0.2
PORTREVISION=	1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		klaus.goger@reflex.at
COMMENT=	Bust-A-Move/Puzzle Bubble clone

LIB_DEPENDS=		png.5:${PORTSDIR}/graphics/png

MAN6=			xbubble.6

USE_X_PREFIX=		Yes
GNU_CONFIGURE=		Yes
USE_GMAKE=		Yes

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include/libpng" \
			LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
