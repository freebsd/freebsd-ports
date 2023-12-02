PORTNAME=	zeal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	devel

PATCH_SITES=	https://github.com/zealdocs/zeal/commit/
PATCHFILES+=	9630cc94c155d87295e51b41fbab2bd5798f8229.patch:-p1 # Fix build with Qt >= 6.6.0

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Offline documentation browser
WWW=		https://zealdocs.org

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxcb.so:x11/libxcb \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang desktop-file-utils gl kde:5 \
		libarchive pkgconfig qt:6 sqlite xorg
USE_GITHUB=	yes
GH_ACCOUNT=	zealdocs
USE_GL=		opengl
USE_KDE=	ecm
USE_QT=		base declarative positioning webchannel webengine
USE_XORG=	ice sm x11 xcb xext

.include <bsd.port.mk>
