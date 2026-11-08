PORTNAME=	darling-dmg
DISTVERSIONPREFIX=v
DISTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	filesystems sysutils

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	FUSE module for .dmg files (containing an HFS+ filesystem)
WWW=		https://github.com/darlinghq/darling-dmg

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libxml2>0:textproc/libxml2
LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake fuse gnome ssl
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	darlinghq
GH_PROJECT=	darling-dmg
GH_TAGNAME=	1a6de10

PLIST_FILES=	bin/darling-dmg \
		lib/libdmg.so

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>
