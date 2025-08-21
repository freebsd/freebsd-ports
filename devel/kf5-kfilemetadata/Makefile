PORTNAME=	kfilemetadata
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	4
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for extracting file metadata

LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libepub.so:textproc/ebook-tools \
		libexiv2.so:graphics/exiv2 \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libtag.so:audio/taglib
# TODO: maybe depend on textproc/catdoc

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig \
		qt:5 tar:xz
USE_KDE=	archive config coreaddons i18n \
		ecm:build
USE_QT=		core gui xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	MOBIPOCKET
OPTIONS_SUB=	yes

MOBIPOCKET_DESC=	Mobipocket plugin to handle metadata
MOBIPOCKET_LIB_DEPENDS=	libqmobipocket.so:graphics/kdegraphics-mobipocket@qt5
MOBIPOCKET_BROKEN=	does not build with KDE Gear 25.08

.include <bsd.port.mk>
