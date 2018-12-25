# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	qlipper
PORTVERSION=	5.1.1
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Lightweight clipboard history applet

LICENSE=	GPLv2

USES=		cmake compiler:c++11-lang gettext qt:5
USE_GITHUB=	yes

GH_ACCOUNT=	pvanek
GH_TAGNAME=	5.1.1

OPTIONS_DEFINE=	LXQTAUTOSTART
OPTIONS_DEFAULT=LXQTAUTOSTART
OPTIONS_SUB=	yes

LXQTAUTOSTART_DESC=		Create autostart entry for LXQt
LXQTAUTOSTART_BUILD_DEPENDS=	${LOCALBASE}/share/cmake/lxqt-build-tools/lxqt-build-tools-config.cmake:devel/lxqt-build-tools
LXQTAUTOSTART_CMAKE_BOOL=	ENABLE_LXQT_AUTOSTART

USE_QT=		buildtools_build qmake_build core gui linguisttools \
		network widgets

USE_XORG=	x11

.include <bsd.port.mk>
