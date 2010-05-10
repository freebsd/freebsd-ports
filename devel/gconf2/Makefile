# New ports collection makefile for:	gconf2
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/gconf2/Makefile,v 1.111 2010/04/01 15:59:40 kwm Exp $
#

PORTNAME=	gconf2
PORTVERSION=	2.28.1
PORTREVISION?=	0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/GConf/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	GConf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A configuration database system for GNOME

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehier gnomehack orbit2 gtk20 libxml2 ltverhack \
		referencehack intlhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
#		--enable-gconf-source=${PREFIX}/etc/gconf/schemas \

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAN1=		gconftool-2.1

OPTIONS=	LDAP "Enable LDAP support" off

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-openldap
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=--without-openldap
PLIST_SUB+=	LDAP="@comment "
.endif

.include <bsd.port.post.mk>

.endif
