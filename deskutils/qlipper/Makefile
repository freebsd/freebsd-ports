PORTNAME=	qlipper
PORTVERSION=	6.1.0
CATEGORIES=	deskutils

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Lightweight clipboard history applet
WWW=		https://github.com/pvanek/qlipper

LICENSE=	GPLv2

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon
USES=		cmake compiler:c++11-lang gettext gl kde:6 xorg perl5 qt:6
USE_GITHUB=	yes

GH_ACCOUNT=	pvanek

OPTIONS_DEFINE=	LXQTAUTOSTART
OPTIONS_DEFAULT=LXQTAUTOSTART
OPTIONS_SUB=	yes

LXQTAUTOSTART_DESC=		Create autostart entry for LXQt
LXQTAUTOSTART_BUILD_DEPENDS=	${LOCALBASE}/share/cmake/lxqt2-build-tools/lxqt2-build-tools-config.cmake:devel/lxqt2-build-tools
LXQTAUTOSTART_CMAKE_BOOL=	ENABLE_LXQT_AUTOSTART

USE_PERL5=	build
USE_KDE=	guiaddons
USE_XORG=	x11 xcb
USE_QT=		base translations
USE_GL=		opengl

USE_XORG=	x11

post-patch:
	@${REINPLACE_CMD} -e 's|2016|2026|g' ${WRKSRC}/src/qlippersystray.cpp

.include <bsd.port.mk>
