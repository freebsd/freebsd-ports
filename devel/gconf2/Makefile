# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/gconf2/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	gconf2
PORTVERSION=	3.2.6
PORTREVISION=	4
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME/sources/GConf/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	GConf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Configuration database system for GNOME

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libpolkit-gobject-1.so:sysutils/polkit

USES+=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	orbit2 gtk20 libxml2 \
		referencehack intlhack dconf introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--with-gtk=2.0 \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/gconf

OPTIONS_DEFINE=	LDAP DOCS
OPTIONS_SUB=	yes

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	openldap

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gconf/gconf.xml.system

.include <bsd.port.mk>

.endif
