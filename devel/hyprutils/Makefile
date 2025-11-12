PORTNAME=	hyprutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.2
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hyprland utilities library used across the ecosystem
WWW=		https://github.com/hyprwm/hyprutils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lib pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_LDCONFIG=	yes
USE_XORG=	pixman

LDFLAGS+=	-pthread

PLIST_SUB=	SOVERSION_MAJOR=9 \
		SOVERSION_FULL=${DISTVERSION:C/-.*//}

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's|/etc|${PREFIX}&|' \
		${WRKSRC}/src/path/Path.cpp

.include <bsd.port.mk>
