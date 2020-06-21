# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	notify-sharp
PORTVERSION=	3.0.3
CATEGORIES=	devel
MASTER_SITES=	https://www.meebey.net/projects/notify-sharp/downloads/

MAINTAINER=	fox@FreeBSD.org
COMMENT=	C\# client library for notification-daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-2.0.pc:devel/dbus-sharp \
		${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-2.0.pc:devel/dbus-sharp-glib \
		${LOCALBASE}/libdata/pkgconfig/gtk-sharp-3.0.pc:x11-toolkits/gtk-sharp30
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-2.0.pc:devel/dbus-sharp \
		${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-2.0.pc:devel/dbus-sharp-glib \
		${LOCALBASE}/libexec/notification-daemon:deskutils/notification-daemon

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GMCS=${LOCALBASE}/bin/mcs
USES=		gmake gnome mono pathfix pkgconfig

.include <bsd.port.mk>
