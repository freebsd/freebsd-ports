PORTNAME=	glibmm
PORTVERSION=	2.76.0
CATEGORIES=	devel
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	26
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib2
WWW=		https://www.gtkmm.org/

LICENSE=	LGPL21

USES=		compiler:c++11-lang gettext gnome meson pathfix perl5 \
		pkgconfig python:build shebangfix tar:xz
USE_GNOME=	glib20 libsigc++30
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py

MESON_ARGS=	-Dbuild-documentation=false

PORTSCOUT=	limit:^2\.72
PLIST_SUB=	VERSION=2.68

.include <bsd.port.mk>
