PORTNAME=		kexi
DISTVERSION=		3.2.0
PORTREVISION=	8
CATEGORIES=		databases kde
MASTER_SITES=		KDE/stable/${PORTNAME}/src
DIST_SUBDIR=		KDE/${PORTNAME}

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Visual database applications creator
WWW=		https://www.kexi-project.org/

LIB_DEPENDS=		libKDb3.so:databases/kdb \
			libKPropertyCore3.so:x11-toolkits/kproperty \
			libKReport3.so:textproc/kreport

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl gnome \
		iconv kde:5 pkgconfig qt:5 tar:xz xorg
USE_GL=			gl
USE_GNOME=	glib20
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes itemviews \
		jobwidgets kio parts service solid sonnet syntaxhighlighting \
		texteditor textwidgets widgetsaddons windowsystem xmlgui \
		breeze-icons:build ecm:build
USE_QT=		concurrent core dbus declarative gui network printsupport \
		widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

CONFLICTS_INSTALL=	calligra-2*

CMAKE_OFF=		BUILD_TESTING \
			KEXI_ENABLE_QTGUI_FOR_TESTS
CMAKE_ON=		KEXI_QTGUI_RUNTIME_AVAILABLE

.include <bsd.port.mk>
