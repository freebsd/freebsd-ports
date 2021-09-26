PORTNAME=	libsigc++
PORTVERSION=	3.0.7
CATEGORIES=	devel
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	30

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++17-lang meson tar:xz
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbuild-documentation=false \
		-Dbuild-examples=false

PLIST_SUB=	API_VERSION="3.0"

.include <bsd.port.mk>
