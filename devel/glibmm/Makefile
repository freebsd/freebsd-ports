PORTNAME=	glibmm
PORTVERSION=	2.66.4
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib2

LICENSE=	LGPL21

USES=		compiler:c++11-lang gettext gnome meson pathfix perl5 \
		pkgconfig python:3.7+,build shebangfix tar:xz
USE_GNOME=	glib20 libsigc++20
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py

MESON_ARGS=	-Dbuild-documentation=false

# 2.68 and later are currently incompatible with consumers
PORTSCOUT=	limit:^2\.66
PLIST_SUB=	VERSION=2.4

.include <bsd.port.mk>
