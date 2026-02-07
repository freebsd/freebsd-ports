PORTNAME=	budgie-desktop-view
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	deskutils budgie
MASTER_SITES=	BUDGIE

PATCH_SITES=	https://github.com/BuddiesOfBudgie/${PORTNAME}/commit/
PATCHFILES+=	05a9822.patch:-p1

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Budgie desktop icons application / implementation
WWW=		https://github.com/BuddiesOfBudgie/budgie-desktop-view

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		budgie gettext-tools gnome meson pkgconfig tar:xz vala:build
USE_BUDGIE=	raven:run
USE_GNOME=	glib20 gtk30 gdkpixbuf intltool:build
MESON_ARGS=	-Dwerror=false

GLIB_SCHEMAS=	org.buddiesofbudgie.budgie-desktop-view.gschema.xml

.include <bsd.port.mk>
