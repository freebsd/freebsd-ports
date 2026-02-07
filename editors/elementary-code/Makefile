PORTNAME=	code
DISTVERSION=	8.1.2
CATEGORIES=	editors
PKGNAMEPREFIX=	elementary-

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Code editor designed for elementary OS
WWW=		https://github.com/elementary/code

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libeditorconfig.so:editors/editorconfig-core-c \
		libfontconfig.so:x11-fonts/fontconfig \
		libgee-0.8.so:devel/libgee \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy \
		libpeas-2.so:devel/libpeas \
		libsoup-3.0.so:devel/libsoup3
RUN_DEPENDS=	droid-fonts-ttf>0:x11-fonts/droid-fonts-ttf \
		pkcheck:sysutils/polkit

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gnome \
		meson pkgconfig vala:lib
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	cairo glib20 gtk30 gtksourceview4 pango vte3
GLIB_SCHEMAS=	io.elementary.code.gschema.xml
USE_LDCONFIG=	yes

.include <bsd.port.mk>
