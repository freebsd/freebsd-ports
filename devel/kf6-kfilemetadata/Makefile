PORTNAME=	kfilemetadata
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for extracting the text and metadata from a number files

LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libepub.so:textproc/ebook-tools \
		libexiv2.so:graphics/exiv2 \
		libpoppler.so:graphics/poppler \
		libpoppler-qt6.so:graphics/poppler-qt6 \
		libtag.so:audio/taglib

USES=		cmake gettext-tools gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	archive codecs config coreaddons i18n \
		ecm:build
USE_QT=		base \
		declarative:build

OPTIONS_DEFINE=	MOBIPOCKET
OPTIONS_DEFAULT=	MOBIPOCKET
OPTIONS_SUB=	yes

MOBIPOCKET_DESC=	Mobipocket plugin to handle metadata
MOBIPOCKET_LIB_DEPENDS=	libQMobipocket6.so:graphics/kdegraphics-mobipocket

.include <bsd.port.mk>
