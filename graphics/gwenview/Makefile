# $FreeBSD$

PORTNAME=	gwenview
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and browser for KDE

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml
LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png

USES=		compiler:c++11-lang cmake gettext jpeg pkgconfig \
		kde:5 qt:5 tar:xz
USE_KDE=	activities auth baloo bookmarks codecs completion config \
		configwidgets coreaddons ecm emoticons filemetadata i18n \
		iconthemes init itemmodels itemviews jobwidgets \
		kdelibs4support kimageformats kio libkdcraw libkipi \
		notifications parts service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network opengl phonon4 printsupport \
		svg widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
