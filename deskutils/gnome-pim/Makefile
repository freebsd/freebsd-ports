# New ports collection makefile for:	gnomepim
# Date created:				17 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepim
PORTVERSION=	1.2.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-pim
DISTNAME=	gnome-pim-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	panel_applet.4:${PORTSDIR}/x11/gnomecore

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
