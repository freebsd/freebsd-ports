PORTNAME=	kfilemetadata
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

COMMENT=	Library for extracting the text and metadata from a number files
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libepub.so:textproc/ebook-tools \
		libexiv2.so:graphics/exiv2 \
		libpoppler.so:graphics/poppler \
		libpoppler-qt6.so:graphics/poppler-qt6 \
		libtag.so:audio/taglib

USES=		cmake gettext gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	archive config coreaddons i18n codecs\
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	MOBIPOCKET
OPTIONS_DEFAULT=	MOBIPOCKET
OPTIONS_SUB=	yes

MOBIPOCKET_DESC=	Mobipocket plugin to handle metadata
MOBIPOCKET_LIB_DEPENDS=	libQMobipocket6.so:graphics/kdegraphics-mobipocket@qt6

.include <bsd.port.mk>
