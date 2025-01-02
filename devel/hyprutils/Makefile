PORTNAME=	hyprutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	111985ee8ade.patch:-p1 # https://github.com/hyprwm/hyprutils/pull/30

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
PLIST_SUB=	VERSION=0.3.1 # XXX Drop after 0.3.3

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's,/etc,${PREFIX}&,' \
		${WRKSRC}/src/path/Path.cpp

.include <bsd.port.mk>
