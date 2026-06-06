PORTNAME=	atkmm
DISTVERSION=	2.28.5
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for ATK API library
WWW=		https://gtkmm.gnome.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang gnome localbase:ldflags meson pkgconfig \
		python:build tar:xz
USE_GNOME=	atk glibmm libsigc++20
USE_LDCONFIG=	yes

MESON_ARGS=	-Dmaintainer-mode=false

.include <bsd.port.mk>
