# New ports collection makefile for:	goffice
# Date created:				07 June 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/devel/goffice/Makefile,v 1.3 2010/06/29 10:56:38 kwm Exp $
#
# !!! When updating goffice, don't forget to update pkg-plist in:
#     math/gnumeric science/gchemutils

PORTNAME=	goffice
PORTVERSION=	0.8.13
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GTK+ set of document centric objects and utilities

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgsf gconf2 \
		ltverhack
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION} \
		SHORT_VER=0.8

.include <bsd.port.mk>
