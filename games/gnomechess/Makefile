# New ports collection makefile for:	gnomechess
# Date created:				29 January 2000
# Whom:					Jeremy Lea <reg@shale.csir.co.za>
#
# $FreeBSD$
#

PORTNAME=	gnomechess
PORTVERSION=	0.2.4
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-chess
DISTNAME=	gnome-chess-${PORTVERSION}

MAINTAINER=	reg@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		crafty:${PORTSDIR}/games/crafty
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		crafty:${PORTSDIR}/games/crafty

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
