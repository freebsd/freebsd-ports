# Created by: Adam Weinberger <adamw@FreeBSD.org>

PORTNAME=	glibmm
PORTVERSION=	2.70.0
CATEGORIES=	devel
MASTER_SITES=	GNOME
PKGMAMESUFFIX=	268
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib2

LICENSE=	LGPL21

LIB_DEPENDS=	libsigc-3.0.so:devel/libsigc++30

USES=		compiler:c++11-lang gettext gnome meson pathfix perl5 \
		pkgconfig python:3.7+,build shebangfix tar:xz
USE_GNOME=	glib20 libsigc++20
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py

MESON_ARGS=	-Dbuild-documentation=false

PLIST_SUB=	VERSION=2.68

.include <bsd.port.mk>
