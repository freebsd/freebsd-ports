# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/libgsf/Makefile,v 1.35 2010/04/10 08:51:15 kwm Exp $

PORTNAME=	libgsf
PORTVERSION=	1.14.21
PORTREVISION?=	1
CATEGORIES?=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Extensible I/O abstraction for dealing with structured file formats

.if !exists(/usr/lib/libbz2.so)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME?=	gnomehack gnomeprefix glib20 libxml2 ltverhack intlhack
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS?=--without-gnome-vfs --without-python --with-gio \
		--without-bonobo
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(GSF_SLAVE)
MAN1=		gsf.1 gsf-office-thumbnailer.1 gsf-vba-dump.1
.endif

OPTIONS_DEFINE=	GCONF
OPTIONS_DEFAULT=	GCONF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
. if !defined(GSF_SLAVE)
GCONF_SCHEMAS=	gsf-office-thumbnailer.schemas
PLIST_FILES+=	bin/gsf-office-thumbnailer
. endif
.else
CONFIGURE_ARGS+=	--without-gconf
.endif

.include <bsd.port.mk>
