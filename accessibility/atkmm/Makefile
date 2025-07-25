PORTNAME=	atkmm
DISTVERSION=	2.28.4
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for ATK API library
WWW=		https://www.gtkmm.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang gnome localbase:ldflags meson pkgconfig \
		python:build tar:xz
USE_GNOME=	atk glibmm libsigc++20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
