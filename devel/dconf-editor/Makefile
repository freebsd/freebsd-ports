# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dconf-editor
PORTVERSION=	3.22.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Configuration database editor for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dconf>=0.23.2:devel/dconf \
		vala>=0.18.1:lang/vala
LIB_DEPENDS=	libdconf.so:devel/dconf

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	cairo intltool gtk30 libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
GLIB_SCHEMAS=	ca.desrt.dconf-editor.gschema.xml

.include <bsd.port.mk>
