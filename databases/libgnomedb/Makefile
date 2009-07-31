# New ports collection makefile for:	libgnomedb
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/libgnomedb/Makefile,v 1.32 2008/02/05 13:09:24 kwm Exp $
#

PORTNAME=	libgnomedb
PORTVERSION=	3.0.0
PORTREVISION?=	4
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library components for the GNOME database frontend

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgda3 gtksourceview \
		intlhack referencehack
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	libgnomedb-3.0.schemas

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
.endif
