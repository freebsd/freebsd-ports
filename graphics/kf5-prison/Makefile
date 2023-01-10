PORTNAME=	prison
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	graphics kde kde-frameworks

PATCH_SITES=	https://invent.kde.org/frameworks/prison/-/commit/
PATCHFILES=	14fb6f0a31373b242bdeb18cf9f3a36441bf86b5.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	API to produce barcodes

LIB_DEPENDS=	libdmtx.so:graphics/libdmtx \
		libqrencode.so:graphics/libqrencode \
		libZXing.so:textproc/zxing-cpp

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm:build
USE_QT=		core declarative gui multimedia network widgets \
		buildtools:build qmake:build testlib:build

.include <bsd.port.mk>
