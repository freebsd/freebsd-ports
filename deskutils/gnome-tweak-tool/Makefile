# Created by: Jeremy Messenger <mezz@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/deskutils/gnome-tweak-tool/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	gnome-tweak-tool
PORTVERSION=	3.12.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Allows to tweak some hidden settings in GTK3 / GNOME3

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		gettext gmake pathfix pkgconfig python:2 tar:xz
USE_GNOME=	gnomeprefix gtk30 pygobject3
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
