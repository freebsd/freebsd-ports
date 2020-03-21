# $FreeBSD$

PORTNAME=	kfilemetadata
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
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
USE_KDE=	archive config coreaddons ecm i18n
USE_QT=		buildtools_build core qmake_build xml

# Frameworks ports install localization files that conflict with some
# KDE4 localization ports
CONFLICTS_INSTALL=     kde4-l10n-*

.include <bsd.port.mk>
