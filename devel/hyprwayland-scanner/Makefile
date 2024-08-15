PORTNAME=	hyprwayland-scanner
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Hyprland implementation of wayland-scanner
WWW=		https://github.com/hyprwm/hyprwayland-scanner

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++11-lib pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm
PLIST_FILES=	bin/${PORTNAME} \
		lib/cmake/${PORTNAME}/${PORTNAME}-config-version.cmake \
		lib/cmake/${PORTNAME}/${PORTNAME}-config.cmake \
		libdata/pkgconfig/${PORTNAME}.pc

# XXX Drop after FreeBSD 14.0 EOL around 2024-10-01
.if exists(/usr/include/c++/v1/__format/format_functions.h) && \
   !exists(/usr/include/c++/v1/__format/write_escaped.h)
CXXFLAGS+=	-fexperimental-library
.endif

.include <bsd.port.mk>
