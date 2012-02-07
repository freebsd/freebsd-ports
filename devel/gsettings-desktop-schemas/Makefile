# New ports collection makefile for:	gsettings-desktop-schemas
# Date created:				14 Aug 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/gsettings-desktop-schemas/Makefile,v 1.13 2011/04/27 21:18:30 kwm Exp $
#

PORTNAME=	gsettings-desktop-schemas
PORTVERSION=	3.0.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of globally shared GSetting schemas

RUN_DEPENDS=	${LOCALBASE}/etc/fonts/conf.avail/31-cantarell.conf:${PORTSDIR}/x11-fonts/cantarell-fonts

LICENSE=	LGPL21

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_GNOME=	gnomehack intltool glib20
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.desktop.a11y.applications.gschema.xml \
		org.gnome.desktop.a11y.keyboard.gschema.xml \
		org.gnome.desktop.a11y.magnifier.gschema.xml \
		org.gnome.desktop.a11y.mouse.gschema.xml \
		org.gnome.desktop.background.gschema.xml \
		org.gnome.desktop.default-applications.gschema.xml \
		org.gnome.desktop.enums.xml \
		org.gnome.desktop.interface.gschema.xml \
		org.gnome.desktop.lockdown.gschema.xml \
		org.gnome.desktop.media-handling.gschema.xml \
		org.gnome.desktop.screensaver.gschema.xml \
		org.gnome.desktop.session.gschema.xml \
		org.gnome.desktop.sound.gschema.xml \
		org.gnome.desktop.thumbnailers.gschema.xml \
		org.gnome.desktop.thumbnail-cache.gschema.xml \
		org.gnome.system.proxy.gschema.xml

.include <bsd.port.mk>
