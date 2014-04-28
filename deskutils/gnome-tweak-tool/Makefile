# Created by: Jeremy Messenger <mezz@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/deskutils/gnome-tweak-tool/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	gnome-tweak-tool
PORTVERSION=	3.12.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Allows to tweak some hidden settings in GTK3 / GNOME3

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 pygobject3
USE_PYTHON=	2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
