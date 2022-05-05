PORTNAME=	qcoro
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Coroutines for Qt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

USES=		cmake compiler:c++17-lang pkgconfig qt:5
USE_QT=		concurrent core dbus network testlib \
		buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	danvratil

CMAKE_OFF=	QCORO_BUILD_EXAMPLES
CMAKE_ARGS=	-DUSE_QT_VERSION=5

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	b4abc5874103.patch:-p1

.include <bsd.port.mk>
