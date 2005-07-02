# New ports collection makefile for:	glade2
# Date created:		02 June 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glade2
PORTVERSION=	2.10.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.10
DISTNAME=	glade-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A user interface builder for GTK+/GNOME

RUN_DEPENDS=	${X11BASE}/lib/gtk-2.0/modules/libgail-gnome.so:${PORTSDIR}/x11-toolkits/libgail-gnome

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomedb libgnomeui
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-gnome-db
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
