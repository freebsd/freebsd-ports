PORTNAME=	hyprlang
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Library to parse hypr config files
WWW=		https://hyprland.org/hyprlang

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	hyprwm
PLIST_FILES=	include/${PORTNAME}.hpp \
		lib/lib${PORTNAME}.so \
		lib/lib${PORTNAME}.so.2 \
		lib/lib${PORTNAME}.so.${PORTVERSION} \
		libdata/pkgconfig/${PORTNAME}.pc

# XXX Drop after FreeBSD 14.0 EOL around 2024-10-01
.if exists(/usr/lib/libc++.so) && !exists(/usr/include/c++/v1/__format/write_escaped.h)
CXXFLAGS+=	-fexperimental-library
.endif

.include <bsd.port.mk>
