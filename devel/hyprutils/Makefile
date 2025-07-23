PORTNAME=	hyprutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	b074d4abc76ce8e740b35ce29534b443ccbc971b.patch:-p1 # atomic shared pointer, see #67
PATCHFILES+=	172a3fc2320d5e919d341510d97fa06f878167c8.patch:-p1 # atomic shared pointer, see #67

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hyprland utilities library used across the ecosystem
WWW=		https://github.com/hyprwm/hyprutils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib cmake:testing pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_LDCONFIG=	yes
USE_XORG=	pixman

LDFLAGS+=	-pthread

PLIST_SUB=	SOVERSION_MAJOR=7 \
		SOVERSION_FULL=${DISTVERSION:C/-.*//}

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's|/etc|${PREFIX}&|' \
		${WRKSRC}/src/path/Path.cpp

.include <bsd.port.mk>
