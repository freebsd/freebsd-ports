# New ports collection makefile for:	libgsf
# Date created:				11 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libgsf/Makefile,v 1.27 2006/10/04 00:03:42 ahze Exp $
#

PORTNAME=	libgsf
PORTVERSION=	1.14.4
PORTREVISION?=	0
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	An extensible i/o abstraction for dealing with structured file formats

.if !exists(/usr/lib/libbz2.so)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME?=	gnomehack gnomeprefix glib20 libxml2 gconf2 ltverhack intlhack
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc --without-gnome --with-bz2 \
		--mandir=${PREFIX}/man \
		--with-gconf-source=${GCONF_CONFIG_SOURCE} \
		--without-python
CONFIGURE_ENV?=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(GSF_SLAVE)
GCONF_SCHEMAS=	gsf-office-thumbnailer.schemas
MAN1=		gsf-office-thumbnailer.1
.endif

.include <bsd.port.mk>
