# New ports collection makefile for:	goffice
# Date created:				07 June 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/goffice/Makefile,v 1.32 2007/09/06 05:01:28 marcus Exp $
#

PORTNAME=	goffice
PORTVERSION=	0.4.3
PORTREVISION=	6
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GTK+ set of document centric objects and utilities

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

NO_LATEST_LINK=	yes

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeprint libglade2 \
		libgsf_gnome libgnomeui ltverhack
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
