# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/gsettings-desktop-schemas/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gsettings-desktop-schemas
PORTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of globally shared GSetting schemas

LICENSE=	LGPL21

RUN_DEPENDS=	${LOCALBASE}/etc/fonts/conf.avail/31-cantarell.conf:${PORTSDIR}/x11-fonts/cantarell-fonts

USE_XZ=		yes
USES=		gettext gmake pathfix perl5 pkgconfig
USE_PERL5=	build
USE_GNOME=	intltool glib20 gnomehier introspection:build
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.desktop.a11y.applications.gschema.xml \
		org.gnome.desktop.a11y.keyboard.gschema.xml \
		org.gnome.desktop.a11y.magnifier.gschema.xml \
		org.gnome.desktop.a11y.mouse.gschema.xml \
		org.gnome.desktop.background.gschema.xml \
		org.gnome.desktop.default-applications.gschema.xml \
		org.gnome.desktop.enums.xml \
		org.gnome.desktop.input-sources.gschema.xml \
		org.gnome.desktop.interface.gschema.xml \
		org.gnome.desktop.lockdown.gschema.xml \
		org.gnome.desktop.media-handling.gschema.xml \
		org.gnome.desktop.screensaver.gschema.xml \
		org.gnome.desktop.session.gschema.xml \
		org.gnome.desktop.sound.gschema.xml \
		org.gnome.desktop.thumbnailers.gschema.xml \
		org.gnome.desktop.thumbnail-cache.gschema.xml \
		org.gnome.desktop.wm.keybindings.gschema.xml \
		org.gnome.desktop.wm.preferences.gschema.xml \
		org.gnome.system.locale.gschema.xml \
		org.gnome.system.proxy.gschema.xml

.include <bsd.port.mk>
