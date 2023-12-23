PORTNAME=	cjs
PORTVERSION=	5.4.1
PORTREVISION=	2
CATEGORIES=	lang gnome
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/gjs/-/commit/
PATCHFILES=	f93880c356108cfdbc8f9ebe318d18f256d7128d.patch:-p1 # https://gitlab.gnome.org/GNOME/gjs/-/issues/514

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JavaScript bindings based on gobject-introspection
WWW=		https://github.com/linuxmint/cjs

LICENSE=		MIT LGPL20+
LICENSE_COMB=		dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT.txt
LICENSE_FILE_LGPL20+ =	${WRKSRC}/LICENSES/LGPL-2.0-or-later.txt

LIB_DEPENDS=	libffi.so:devel/libffi \
		libmozjs-78.so:lang/spidermonkey78

USES=		compiler:c++17-lang gettext gnome localbase meson pkgconfig \
		python:build readline shebangfix xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection
USE_XORG=	x11 xext
MESON_ARGS=	-Dinstalled_tests=false \
		-Dprofiler=disabled
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_GLOB=	*.py

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

.include <bsd.port.mk>
