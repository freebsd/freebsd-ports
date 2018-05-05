# $FreeBSD$

PORTNAME=	libappindicator
PORTVERSION=	12.10.0
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	KSNI App Indicator library

LIB_DEPENDS=	libdbusmenu-gtk3.so:devel/libdbusmenu \
		libindicator3.so:devel/libindicator

USES=		gmake libtool pkgconfig python
USE_LDCONFIG=	yes
USE_GNOME=	gtk30 pygtk2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=3

.include <bsd.port.mk>
