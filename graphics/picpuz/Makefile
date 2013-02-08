# New ports collection makefile for: graphics/picpuz
# Date created:		04 Jan 2010
# Whom:			Stas Timokhin <devel@stasyan.com>
#
# $FreeBSD$
#

PORTNAME=	picpuz
PORTVERSION=	2.1.1
PORTREVISION=	4
CATEGORIES=	graphics games
MASTER_SITES=	http://kornelix.squarespace.com/storage/downloads/

MAINTAINER=	devel@stasyan.com
COMMENT=	Jigsaw puzzle program

USE_GMAKE=	yes
USE_GNOME=	gtk20 pkgconfig

ALL_TARGET=	#
#RUN_DEPENDS+=	xdg-desktop-menu:${PORTSDIR}/devel/xdg-utils
LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo
DESKTOP_ENTRIES="Picpuz" \
		"Jigsaw Puzzle" \
		"${PREFIX}/share/pixmaps/picpuz.png" \
		"picpuz" \
		"Graphics;Game;GTK;" \
		true

.include <bsd.port.mk>
