# New ports collection makefile for:    librsvg2
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librsvg2
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.4
DISTNAME=	librsvg-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		popt.0:${PORTSDIR}/devel/popt \
		gsf-1.9:${PORTSDIR}/devel/libgsf
RUN_DEPENDS=	${X11BASE}/lib/gtk-2.0/2.2.0/engines/libmetal.so:${PORTSDIR}/x11-toolkits/gtk-engines2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnomehack gtk20 libartlgpl2 libxml2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-svgz \
		--disable-gtk-doc \
		--without-gimp
PLIST_SUB=	GTK_VERSION="2.2.0"

MAN1=		rsvg.1

.include <bsd.port.mk>
