# New ports collection makefile for:	bonobo
# Version required:			0.8
# Date created:				8th October 1999
# Whom:					Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

DISTNAME=	bonobo-0.8
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/bonobo

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs \
		intl.1:${PORTSDIR}/devel/gettext \
		gdk_pixbuf.1:${PORTSDIR}/graphics/gdk-pixbuf \
		xml.5:${PORTSDIR}/textproc/libxml

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libefs/configure
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
