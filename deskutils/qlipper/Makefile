PORTNAME=	qlipper
PORTVERSION=	5.1.2
CATEGORIES=	deskutils

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Lightweight clipboard history applet
WWW=		https://github.com/pvanek/qlipper

LICENSE=	GPLv2

USES=		cmake compiler:c++11-lang gettext perl5 qt:5 xorg
USE_GITHUB=	yes

GH_ACCOUNT=	pvanek

OPTIONS_DEFINE=	LXQTAUTOSTART
OPTIONS_DEFAULT=LXQTAUTOSTART
OPTIONS_SUB=	yes

LXQTAUTOSTART_DESC=		Create autostart entry for LXQt
LXQTAUTOSTART_BUILD_DEPENDS=	${LOCALBASE}/share/cmake/lxqt-build-tools/lxqt-build-tools-config.cmake:devel/lxqt-build-tools
LXQTAUTOSTART_CMAKE_BOOL=	ENABLE_LXQT_AUTOSTART

USE_PERL5=	build

USE_QT=		buildtools:build qmake:build core gui linguisttools \
		network widgets

USE_XORG=	x11

.include <bsd.port.mk>
