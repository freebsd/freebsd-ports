PORTNAME=	qcoro
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Coroutines for Qt
WWW=		https://github.com/danvratil/qcoro

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

USES=		cmake compiler:c++17-lang pkgconfig qt:5
USE_QT=		concurrent core dbus declarative network testlib websockets \
		buildtools:build qmake:build

USE_GITHUB=	yes
GH_ACCOUNT=	danvratil

CMAKE_OFF=	QCORO_BUILD_EXAMPLES
CMAKE_ARGS=	-DUSE_QT_VERSION=5

BROKEN_FreeBSD_12=	requires recent C++ compiler

.include <bsd.port.mk>
