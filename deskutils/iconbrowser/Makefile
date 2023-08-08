PORTNAME=	iconbrowser
DISTVERSION=	2.1.1
PORTREVISION=	4
CATEGORIES=	deskutils

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Browse and find system icons
WWW=		https://github.com/elementary/iconbrowser

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgranite-7.so:x11-toolkits/granite7 \
		libhandy-1.so:x11-toolkits/libhandy

USES=		gettext-tools gnome meson pkgconfig python:build vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	glib20 gtk40 gtksourceview5
GLIB_SCHEMAS=	io.elementary.iconbrowser.gschema.xml

.include <bsd.port.mk>
