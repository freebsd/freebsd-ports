# New ports collection makefile for:	libgnomedb
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnomedb
PORTVERSION=	1.2.2
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/libgnomedb/1.2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library components for the GNOME database frontend

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgda2 gtksourceview \
		intlhack
USE_LIBTOOL_VER=15
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	libgnomedb.schemas

.include <bsd.port.mk>
