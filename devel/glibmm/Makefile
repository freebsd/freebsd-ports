PORTNAME=	glibmm
DISTVERSION=	2.66.7
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib2
WWW=		https://www.gtkmm.org/

LICENSE=	LGPL21

USES=		compiler:c++11-lang gettext gnome meson pathfix perl5 \
		pkgconfig python:build shebangfix tar:xz
SHEBANG_GLOB=	*.py
USE_GNOME=	glib20 libsigc++20
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbuild-documentation=false \
		-Dbuild-examples=false

# 2.68 and later are currently incompatible with consumers
PORTSCOUT=	limit:^2\.66
PLIST_SUB=	VERSION=2.4

.include <bsd.port.mk>
