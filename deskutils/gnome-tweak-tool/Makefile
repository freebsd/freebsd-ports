# Created by: Jeremy Messenger <mezz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-tweak-tool
PORTVERSION=	3.18.1
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Allows to tweak some hidden settings in GTK3 / GNOME3

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome pathfix pkgconfig python:2.7 \
		shebangfix tar:xz
USE_GNOME=	gtk30 pygobject3 intlhack
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
SHEBANG_FILES=	gnome-tweak-tool

.include <bsd.port.mk>
