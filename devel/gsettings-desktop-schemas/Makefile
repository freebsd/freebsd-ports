# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gsettings-desktop-schemas
PORTVERSION=	3.28.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of globally shared GSetting schemas

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix perl5 pkgconfig tar:xz
USE_PERL5=	build
USE_GNOME=	intltool glib20 introspection:build
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.desktop.a11y.applications.gschema.xml \
		org.gnome.desktop.a11y.gschema.xml \
		org.gnome.desktop.a11y.keyboard.gschema.xml \
		org.gnome.desktop.a11y.magnifier.gschema.xml \
		org.gnome.desktop.a11y.mouse.gschema.xml \
		org.gnome.desktop.app-folders.gschema.xml \
		org.gnome.desktop.background.gschema.xml \
		org.gnome.desktop.calendar.gschema.xml \
		org.gnome.desktop.default-applications.gschema.xml \
		org.gnome.desktop.datetime.gschema.xml \
		org.gnome.desktop.enums.xml \
		org.gnome.desktop.input-sources.gschema.xml \
		org.gnome.desktop.interface.gschema.xml \
		org.gnome.desktop.lockdown.gschema.xml \
		org.gnome.desktop.media-handling.gschema.xml \
		org.gnome.desktop.notifications.gschema.xml \
		org.gnome.desktop.peripherals.gschema.xml \
		org.gnome.desktop.privacy.gschema.xml \
		org.gnome.desktop.screensaver.gschema.xml \
		org.gnome.desktop.search-providers.gschema.xml \
		org.gnome.desktop.session.gschema.xml \
		org.gnome.desktop.sound.gschema.xml \
		org.gnome.desktop.thumbnail-cache.gschema.xml \
		org.gnome.desktop.thumbnailers.gschema.xml \
		org.gnome.desktop.wm.keybindings.gschema.xml \
		org.gnome.desktop.wm.preferences.gschema.xml \
		org.gnome.system.locale.gschema.xml \
		org.gnome.system.location.gschema.xml \
		org.gnome.system.proxy.gschema.xml

.include <bsd.port.mk>
