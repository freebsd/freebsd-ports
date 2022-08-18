PORTNAME=	prison
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	graphics kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	API to produce barcodes

LIB_DEPENDS=	libqrencode.so:graphics/libqrencode

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm:build
USE_QT=		core declarative gui network widgets \
		buildtools:build qmake:build testlib:build

OPTIONS_DEFINE=		BARCODE
OPTIONS_DEFAULT=	BARCODE
OPTIONS_SUB=		yes
BARCODE_DESC=		Data Matrix Barcode support

OPTIONS_EXCLUDE_purecap=	BARCODE

.include <bsd.port.pre.mk>

.if !${ABI:Mpurecap}
USE_QT+=	multimedia
.endif

.if ${PORT_OPTIONS:MBARCODE}
LIB_DEPENDS=	libdmtx.so:graphics/libdmtx \
		libZXing.so:textproc/zxing-cpp
.endif

.include <bsd.port.post.mk>
