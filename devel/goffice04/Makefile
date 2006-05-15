# New ports collection makefile for:	goffice
# Date created:				07 June 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/goffice/Makefile,v 1.9 2006/01/31 22:13:22 ahze Exp $
#

PORTNAME=	goffice
PORTVERSION=	0.2.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GTK+ set of document centric objects and utilities

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeprint libglade2 \
		libgsf_gnome ltverhack
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
