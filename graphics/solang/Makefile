# New ports collection makefile for:	solang
# Date created:		2009-06-11
# Whom:			Ashish SHUKLA <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	solang
PORTVERSION=	0.3
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://rishi.fedorapeople.org/solang/

PATCH_SITES=	http://rishi.fedorapeople.org/
PATCHFILES=	0001-Ported-to-libgdamm-4.x.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	wahjava@gmail.com
COMMENT=	A photo manager for GNOME

LIB_DEPENDS=	gegl-0.1:${PORTSDIR}/graphics/gegl \
		exiv2.7:${PORTSDIR}/graphics/exiv2 \
		flickcurl.0:${PORTSDIR}/www/flickcurl \
		gtkimageview.0:${PORTSDIR}/x11-toolkits/gtkimageview \
		webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2 \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		gdl-1.3:${PORTSDIR}/x11-toolkits/gdl \
		gdamm-4.0.12:${PORTSDIR}/databases/libgdamm \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2

USE_AUTOTOOLS=	autoconf:262
USE_GMAKE=	yes
USE_GNOME=	libgda4 intltool
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_GCC=	4.2+

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
