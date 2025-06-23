PORTNAME=	prison
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	graphics kde kde-frameworks

COMMENT=	Qt-based barcode abstraction layer/library
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libdmtx.so:graphics/libdmtx \
		libqrencode.so:graphics/libqrencode \
		libZXing.so:textproc/zxing-cpp

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base declarative multimedia tools:build

.include <bsd.port.mk>
