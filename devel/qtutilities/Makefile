PORTNAME=	qtutilities
DISTVERSIONPREFIX=	v
DISTVERSION=	6.14.3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common Qt related C++ classes such as dialogs, widgets, models
WWW=		https://github.com/Martchus/qtutilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libc++utilities.so:devel/cpp-utilities

USES=		cmake:testing compiler:c++17-lang qt:5 xorg
USE_QT=		core dbus gui testlib widgets buildtools:build linguisttools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Martchus

MAKE_ENV+=	QT_QPA_PLATFORM=offscreen # otherwise tests fail because they can't connect to display

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ARGS=	-DEXCLUDE_TESTS_FROM_ALL=OFF
CMAKE_TESTING_TARGET=	check

.include <bsd.port.mk>
