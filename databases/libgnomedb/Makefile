# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgnomedb/Makefile,v 1.32 2008/02/05 13:09:24 kwm Exp $

PORTNAME=	libgnomedb
PORTVERSION=	3.0.0
PORTREVISION?=	7
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library components for the GNOME database frontend

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgda3 gtksourceview \
		intlhack referencehack
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DGLIB_COMPILATION
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	libgnomedb-3.0.schemas

PLIST_SUB=	VERSION=${PORTVERSION:R}

NO_STAGE=	yes
.include <bsd.port.mk>
.endif
