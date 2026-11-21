PORTNAME=	kfilemetadata
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for extracting the text and metadata from a number files

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		cmake gettext-tools gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	archive codecs config coreaddons i18n \
		ecm:build
USE_QT=		base \
		declarative:build


.if !defined(PKGNAMESUFFIX)
SUB_FILES=	pkg-message

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Poppler \
		CMAKE_DISABLE_FIND_PACKAGE_LibExiv2 \
		CMAKE_DISABLE_FIND_PACKAGE_FFmpeg \
		CMAKE_DISABLE_FIND_PACKAGE_EPub \
		CMAKE_DISABLE_FIND_PACKAGE_QMobipocket6
.else # kf6-kfilemetadata-plugins
# Split plugings to avoid needless rebuilding of kf6-kfilemetadata
# and its consumers on KDE Gear updates.
COMMENT=	Extra plugins for KFileMetaData

USE_KDE+=	filemetadata
LIB_DEPENDS=	libQMobipocket6.so:graphics/kdegraphics-mobipocket \
		libavutil.so:multimedia/ffmpeg \
		libepub.so:textproc/ebook-tools \
		libexiv2.so:graphics/exiv2 \
		libpoppler.so:graphics/poppler \
		libpoppler-qt6.so:graphics/poppler-qt6 \

BUILD_WRKSRC=	${CONFIGURE_WRKSRC}/src/extractors
INSTALL_WRKSRC=	${BUILD_WRKSRC}
.endif

.include <bsd.port.mk>
