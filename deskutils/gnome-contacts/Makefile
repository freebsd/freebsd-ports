# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-contacts/Makefile 20055 2014-11-10 17:35:24Z gusi $

PORTNAME=	gnome-contacts
PORTVERSION=	3.14.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Contacts manager for gnome

BUILD_DEPENDS=	vala>=0.14.0:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libfolks.so:${PORTSDIR}/net-im/folks \
		libnotify.so:${PORTSDIR}/devel/libnotify

USE_GNOME=	evolutiondataserver3 gnomedesktop3 gtk30 intlhack \
		introspection:build
USES=		gettext gmake pathfix perl5 pkgconfig tar:xz
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

GLIB_SCHEMAS=	org.gnome.Contacts.enums.xml \
		org.gnome.Contacts.gschema.xml

CHEESE_DESC=	Cheese webcam support

OPTIONS_DEFINE_i386=	CHEESE
OPTIONS_DEFAULT_i386=	CHEESE
OPTIONS_DEFINE_amd64=	CHEESE
OPTIONS_DEFAULT_amd64=	CHEESE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHEESE}
CONFIGURE_ARGS+=--with-cheese
LIB_DEPENDS+=	libcheese-gtk.so:${PORTSDIR}/multimedia/cheese
#.else
#BROKEN=		sorry cheese less build is currently borken
#CONFIGURE_ARGS+=--without-cheese
.endif

.include <bsd.port.mk>
