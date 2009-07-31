# New ports collection makefile for:	libgsf
# Date created:				11 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libgsf/Makefile,v 1.33 2009/01/08 01:28:46 marcus Exp $
#

PORTNAME=	libgsf
PORTVERSION=	1.14.15
PORTREVISION?=	1
CATEGORIES?=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	An extensible i/o abstraction for dealing with structured file formats

.if !exists(/usr/lib/libbz2.so)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME?=	gnomehack gnomeprefix glib20 libxml2 ltverhack intlhack
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS?=--without-gnome-vfs --without-python --with-gio \
		--without-bonobo
CONFIGURE_ENV?=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(GSF_SLAVE)
MAN1=		gsf.1 gsf-office-thumbnailer.1 gsf-vba-dump.1
.endif

.if !defined(WITHOUT_GCONF) || exists(${LOCALBASE}/bin/gconftool-2)
USE_GNOME+=	gconf2
PLIST_SUB+=	THUMB=""
. if !defined(GSF_SLAVE)
GCONF_SCHEMAS=	gsf-office-thumbnailer.schemas
. endif
.else
PLIST_SUB+=	THUMB="@comment "
.endif

.include <bsd.port.mk>
