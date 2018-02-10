# $FreeBSD$

PORTNAME=	easyloggingpp
DISTVERSIONPREFIX=	v
DISTVERSION=	9.95.4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ logging library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	muflihun
USE_LDCONFIG=	yes
CMAKE_ON=	build_shared_lib  # patched in, requested such option in https://github.com/muflihun/easyloggingpp/issues/603

PLIST_FILES=	include/easylogging++.h \
		include/easylogging++.cc \
		lib/libeasyloggingpp.so

.include <bsd.port.mk>
