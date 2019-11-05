# $FreeBSD$

PORTNAME=	kxstitch
DISTVERSION=	2.2.0
PORTREVISION=	1
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross stitch pattern editor

LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick6 \
		libMagickCore-6.so:graphics/ImageMagick6

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 qt:5 tar:xz \
		xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons \
		i18n itemviews jobwidgets kio service solid sonnet textwidgets \
		widgetsaddons xmlgui
USE_QT=		concurrent core dbus gui network printsupport widgets x11extras \
		xml \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
