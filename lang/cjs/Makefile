PORTNAME=	cjs
DISTVERSION=	6.4.0
CATEGORIES=	lang gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cinnamon Javascript interpreter
WWW=		https://github.com/linuxmint/cjs

LICENSE=		MIT LGPL20+
LICENSE_COMB=		dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT.txt
LICENSE_FILE_LGPL20+ =	${WRKSRC}/LICENSES/LGPL-2.0-or-later.txt

LIB_DEPENDS=	libffi.so:devel/libffi \
		libmozjs-115.so:lang/spidermonkey115

USES=		compiler:c++17-lang gnome meson pkgconfig \
		python:build shebangfix xorg
USE_GNOME=	cairo glib20 introspection
USE_XORG=	x11 xext
MESON_ARGS=	-Dprofiler=disabled

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_GLOB=	*.py

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

OPTIONS_DEFINE=		READLINE TEST
OPTIONS_DEFAULT=	READLINE

READLINE_MESON_ENABLED=	readline
READLINE_USES=		readline

TEST_BUILD_DEPENDS=	dbus-run-session:devel/dbus \
			gtk3>0:x11-toolkits/gtk30 \
			gtk4>0:x11-toolkits/gtk40
TEST_MESON_FALSE=	skip_dbus_tests skip_gtk_tests

.include <bsd.port.mk>
