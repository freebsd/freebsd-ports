# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/gconf2/Makefile,v 1.124 2010/11/15 22:14:03 kwm Exp $

PORTNAME=	gconf2
PORTVERSION=	2.32.0
PORTREVISION?=	3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/GConf/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	GConf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A configuration database system for GNOME

USE_BZIP2=	yes

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit

USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gnomehier orbit2 gtk20 libxml2 ltverhack \
		referencehack intlhack dconf introspection:build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	LDAP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-openldap
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=--without-openldap
PLIST_SUB+=	LDAP="@comment "
.endif

post-install:
	-${LOCALBASE}/bin/gio-querymodules ${STAGEDIR}${PREFIX}/lib/gio/modules

.include <bsd.port.mk>

.endif
