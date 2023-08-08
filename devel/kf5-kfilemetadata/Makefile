PORTNAME=	kfilemetadata
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for extracting file metadata

LIB_DEPENDS=	libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5
# TODO: maybe depend on textproc/catdoc

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig \
		qt:5 tar:xz
USE_KDE=	archive config coreaddons i18n \
		ecm:build
USE_QT=		core gui xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=			EPUB EXIV2 FFMPEG TAGLIB
OPTIONS_DEFAULT=		EPUB EXIV2 FFMPEG TAGLIB
OPTIONS_SUB=			yes
OPTIONS_EXCLUDE_purecap=	EPUB EXIV2 FFMPEG TAGLIB

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEPUB}
LIB_DEPENDS+=	libepub.so:textproc/ebook-tools
.endif

.if ${PORT_OPTIONS:MEXIV2}
LIB_DEPENDS+=	libexiv2.so:graphics/exiv2
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavutil.so:multimedia/ffmpeg
.endif

.if ${PORT_OPTIONS:MTAGLIB}
LIB_DEPENDS+=	libtag.so:audio/taglib
.endif

.include <bsd.port.mk>
