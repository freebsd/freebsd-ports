PORTNAME=	hyprlang
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Library to parse hypr config files
WWW=		https://hyprland.org/hyprlang

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	https://github.com/hyprwm/hyprlang/issues/8
BROKEN_i386=	https://github.com/hyprwm/hyprlang/issues/8
BROKEN_powerpc=	https://github.com/hyprwm/hyprlang/issues/8

USES=		cmake:testing compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	hyprwm
PLIST_FILES=	include/${PORTNAME}.hpp \
		lib/lib${PORTNAME}.so \
		share/pkgconfig/${PORTNAME}.pc

# XXX Drop after FreeBSD 14.0 EOL around 2025-03-01
.if exists(/usr/include/c++/v1/__format/format_functions.h) && \
   !exists(/usr/include/c++/v1/__format/write_escaped.h)
CXXFLAGS+=	-fexperimental-library
.endif

.include <bsd.port.mk>
