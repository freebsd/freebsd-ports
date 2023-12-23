PORTNAME=	budgie-desktop-view
DISTVERSION=	1.3
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	deskutils budgie
MASTER_SITES=	BUDGIE

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Budgie desktop icons application / implementation
WWW=		https://github.com/BuddiesOfBudgie/budgie-desktop-view

LICENSE=	APACHE20

USES=		budgie gettext gnome meson pkgconfig tar:xz vala:build
USE_BUDGIE=	raven:run
USE_GNOME=	glib20 gtk30 gdkpixbuf2 intltool

GLIB_SCHEMAS=	org.buddiesofbudgie.budgie-desktop-view.gschema.xml

.include <bsd.port.mk>
