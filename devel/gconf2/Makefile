# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/gconf2/Makefile,v 1.124 2010/11/15 22:14:03 kwm Exp $

PORTNAME=	gconf2
PORTVERSION=	2.32.0
PORTREVISION?=	6
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/GConf/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	GConf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Configuration database system for GNOME

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit

USES+=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	gnomehier orbit2 gtk20 libxml2 \
		referencehack intlhack dconf introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

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

.include <bsd.port.mk>

.endif
