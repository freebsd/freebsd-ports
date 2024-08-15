PORTNAME=	hyprutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Hyprland utilities library used across the ecosystem
WWW=		https://github.com/hyprwm/hyprutils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib cmake:testing pkgconfig xorg
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_XORG=	pixman
GH_ACCOUNT=	hyprwm
PLIST_SUB=	VERSION=${DISTVERSION:C/-.*//}

# XXX Drop after FreeBSD 14.0 EOL around 2024-10-01
.if exists(/usr/lib/libc++.so) && !exists(/usr/include/c++/v1/__format/write_escaped.h)
CXXFLAGS+=	-fexperimental-library
.endif

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's,/etc,${PREFIX}&,' \
		${WRKSRC}/src/path/Path.cpp

.include <bsd.port.mk>
