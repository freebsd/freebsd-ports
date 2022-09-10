PORTNAME=	prison
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	graphics kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	API to produce barcodes

LIB_DEPENDS=	libdmtx.so:graphics/libdmtx \
		libqrencode.so:graphics/libqrencode \
		libZXing.so:textproc/zxing-cpp

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm_build
USE_QT=		core declarative gui multimedia network widgets \
		buildtools_build qmake_build testlib_build

.include <bsd.port.mk>
