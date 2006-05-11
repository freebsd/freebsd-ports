# New ports collection makefile for:	libgnomedb
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/libgnomedb/Makefile,v 1.25 2005/10/13 20:20:19 marcus Exp $
#

PORTNAME=	libgnomedb
PORTVERSION=	1.9.102
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library components for the GNOME database frontend

USE_BZIP2=	yes
PREFIX?=	${X11BASE}

.if !defined(REFERENCE_PORT)

PORTREVISION=	2

USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgda3 gtksourceview \
		intlhack referencehack
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	libgnomedb.schemas

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.mk>

.endif
