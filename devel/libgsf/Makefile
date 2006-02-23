# New ports collection makefile for:	libgsf
# Date created:				11 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libgsf/Makefile,v 1.17 2005/10/11 22:08:17 marcus Exp $
#

PORTNAME=	libgsf
PORTVERSION=	1.13.3
PORTREVISION?=	1
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	An extensible i/o abstraction for dealing with structured file formats

.if !exists(/usr/lib/libbz2.so)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME?=	gnomehack glib20 libxml2 gconf2 ltverhack intlhack
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc --without-gnome --with-bz2 \
		--mandir=${PREFIX}/man \
		--with-gconf-source=${GCONF_CONFIG_SOURCE}
CONFIGURE_ENV?=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(GSF_SLAVE)
GCONF_SCHEMAS=	gsf-office-thumbnailer.schemas
MAN1=		gsf-office-thumbnailer.1
.endif

.include <bsd.port.mk>
