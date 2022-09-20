PORTNAME=	copyq
DISTVERSIONPREFIX=	v
DISTVERSION=	6.3.0
CATEGORIES=	deskutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Qt5 based clipboard manager
WWW=		https://github.com/hluk/CopyQ

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		cmake compiler:c++17-lang desktop-file-utils kde:5 qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	hluk
GH_PROJECT=	CopyQ
USE_KDE=	notifications

USE_QT=		core dbus declarative gui network svg wayland widgets x11extras \
		xml buildtools:build qmake:build
USE_XORG=	ice sm x11 xext xfixes xtst

PORTSCOUT=	limit:^d\.d\.

OPTIONS_DEFINE=		PLUGINS
OPTIONS_DEFAULT=	PLUGINS
OPTIONS_SUB=		yes

PLUGINS_CMAKE_BOOL=	WITH_PLUGINS

.include <bsd.port.mk>
