# Created by: Pawel Worach <pawel.worach@gmail.com>

PORTNAME=	gjs
PORTVERSION=	1.70.1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

LICENSE=	MPL11 LGPL20+ GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_MPL11=	${WRKSRC}/LICENSES/MPL-1.1.txt
LICENSE_FILE_LGPL20+ =	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libmozjs-78.so:lang/spidermonkey78 \
		libffi.so:devel/libffi

USES=		compiler:c++11-lib gettext gnome \
		localbase meson pkgconfig python:build readline tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection
USE_XORG=	x11 xext
MESON_ARGS=	-Dcairo=enabled \
		-Dreadline=enabled \
		-Dprofiler=disabled \
		-Dinstalled_tests=false
USE_LDCONFIG=	yes

CONFIGURE_ENV=	PYTHONDONTWRITEBYTECODE=1
MAKE_ENV=	PYTHONDONTWRITEBYTECODE=1

.include <bsd.port.mk>
