PORTNAME=	qcoro
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Coroutines for Qt

USES=		cmake compiler:c++17-lang pkgconfig qt:5
USE_QT=		concurrent core dbus network testlib \
		buildtools_build qmake_build
USE_GITHUB=	y
GH_ACCOUNT=	danvratil

CMAKE_OFF=	QCORO_BUILD_EXAMPLES
CMAKE_ARGS=	-DUSE_QT_VERSION=5
		#-DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config12

.include <bsd.port.mk>
