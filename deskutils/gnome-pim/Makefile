# New ports collection makefile for:	gnomepim
# Version required:			1.0.55
# Date created:				17 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	gnome-pim-1.0.55
PKGNAME=	gnomepim-1.0.55
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-pim

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore

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
