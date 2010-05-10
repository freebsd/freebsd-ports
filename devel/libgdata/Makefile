# New ports collection makefile for:	libgdata
# Date created:				9 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libgdata/Makefile,v 1.9 2010/03/30 11:24:13 kwm Exp $
#

PORTNAME=	libgdata
PORTVERSION=	0.6.4
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

BUILD_DEPENDS=	${LOCALBASE}/share/gir-1.0/Soup-2.4.gir:${PORTSDIR}/devel/gir-repository-libsoup \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/Soup-2.4.gir:${PORTSDIR}/devel/gir-repository-libsoup

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack intltool ltverhack glib20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--with-html-dir="${PREFIX}/share/doc"

.include <bsd.port.mk>
