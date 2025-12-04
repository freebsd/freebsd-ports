PORTNAME=	zeal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
CATEGORIES=	devel

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Offline documentation browser
WWW=		https://zealdocs.org

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxcb.so:x11/libxcb \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang desktop-file-utils gl kde:6 \
		libarchive pkgconfig qt:6 sqlite xorg
USE_GITHUB=	yes
GH_ACCOUNT=	zealdocs
USE_GL=		opengl
USE_KDE=	ecm
USE_QT=		base declarative positioning webchannel webengine tools:build
USE_XORG=	ice sm x11 xcb xext

.include <bsd.port.mk>
