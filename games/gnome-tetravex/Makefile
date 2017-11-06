# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-tetravex
PORTVERSION=	3.22.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome tetravex

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.tetravex.gschema.xml

.include <bsd.port.mk>
