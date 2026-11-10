PORTNAME=	lxqt-clip
PORTVERSION=	2.5.0
CATEGORIES=	deskutils
DIST_SUBDIR=	lxqt

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	LXQt clipboard history applet
WWW=		https://github.com/lxqt/lxqt-clip/

LICENSE=	GPLv2

LIB_DEPENDS=    libxkbcommon.so:x11/libxkbcommon
USES=           cmake compiler:c++11-lang gettext gl kde:6 lxqt:2 xorg perl5 \
		qt:6 tar:xz

USE_PERL5=      build
USE_KDE=        guiaddons
USE_XORG=       x11 xcb
USE_QT=         base translations tools:build
USE_GL=         opengl
USE_LXQT=	buildtools2 lxqt
USE_XORG=       x11

.include <bsd.port.mk>
