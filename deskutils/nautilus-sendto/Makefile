# New ports collection makefile for:	nautilus-sendto
# Date created:		2004-12-03
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/deskutils/nautilus-sendto/Makefile,v 1.30 2010/09/30 06:21:18 kwm Exp $

PORTNAME=	nautilus-sendto
PORTVERSION=	2.32.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integration between nautilus, evolution, and pidgin

MAN1=		nautilus-sendto.1
GLIB_SCHEMAS=	org.gnome.Nautilus.Sendto.gschema.xml
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	intlhack gnomeprefix gnometarget nautilus2 gnomehack \
		evolutiondataserver
GNOME_DESKTOP_VERSION=2
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-plugins="${SENDTO_PLUGINS}"

OPTIONS=	PIDGIN	"Build pidgin sendto plugin" off \
		UPNP	"Build upnp sendto plugin" off

# check configure script for allowed_plugins="..." for new plugins
SENDTO_PLUGINS=	evolution gajim nautilus-burn removable-devices

.include <bsd.port.pre.mk>

.if defined(WITH_PIDGIN)
SENDTO_PLUGINS:=${SENDTO_PLUGINS} pidgin
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS+=	pidgin:${PORTSDIR}/net-im/pidgin
PLIST_SUB+=	PIDGIN=""
.else
PLIST_SUB+=	PIDGIN="@comment "
.endif

.if defined(WITH_UPNP)
SENDTO_PLUGINS:=${SENDTO_PLUGINS} upnp
LIB_DEPENDS+=	gupnp-1.0:${PORTSDIR}/net/gupnp
PLIST_SUB+=	UPNP=""
.else
PLIST_SUB+=	UPNP="@comment "
.endif

.include <bsd.port.post.mk>
