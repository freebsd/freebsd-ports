# $FreeBSD$

PORTNAME=		kexi
DISTVERSION=		3.1.0
PORTREVISION=	1
CATEGORIES=		databases kde
MASTER_SITES=		KDE/stable/${PORTNAME}/src
DIST_SUBDIR=		KDE/${PORTNAME}

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Visual database applications creator

LIB_DEPENDS=		libKDb3.so:databases/kdb \
			libKPropertyCore3.so:x11-toolkits/kproperty \
			libKReport3.so:textproc/kreport

USES=			cmake:outsource desktop-file-utils gettext iconv \
			kde:5 pkgconfig qt:5 tar:xz
USE_GNOME=		glib20
USE_KDE=		auth bookmarks codecs completion config \
			configwidgets coreaddons crash ecm guiaddons i18n \
			iconthemes itemviews jobwidgets kio parts service \
			solid sonnet texteditor textwidgets widgetsaddons \
			xmlgui breeze-icons_build
USE_QT=			core dbus declarative gui network printsupport webkit widgets xml \
			buildtools_build qmake_build

CONFLICTS_INSTALL=	calligra-2*

CMAKE_ARGS=		-DBUILD_TESTING:BOOL=OFF \
			-DKEXI_QTGUI_RUNTIME_AVAILABLE:BOOL=TRUE \
			-DKEXI_ENABLE_QTGUI_FOR_TESTS:BOOL=FALSE

.include <bsd.port.mk>
