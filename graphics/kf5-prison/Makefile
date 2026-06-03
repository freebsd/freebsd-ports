PORTNAME=	prison
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	API to produce barcodes

DEPRECATED=	has its functionality stripped for coinstallability with Frameworks 6

LIB_DEPENDS=	libdmtx.so:graphics/libdmtx \
		libqrencode.so:graphics/libqrencode

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm:build
USE_QT=		core declarative gui multimedia network \
		buildtools:build qmake:build testlib:build widgets:build

# ZXing 3.x is unsupported
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_ZXing=True

.include <bsd.port.mk>
