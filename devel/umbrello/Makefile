PORTNAME=	umbrello
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	UML modeller for KDE
WWW=		https://umbrello.kde.org/

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake compiler:c++11-lang desktop-file-utils gnome kde:5 qt:5 \
		tar:xz xorg
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes init itemviews \
		jobwidgets kio notifications parts service solid sonnet \
		syntaxhighlighting texteditor textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network printsupport svg widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

post-patch:
# The CMakeFile  sets BUILD_UNITTESTS to 1, not respecting the
# value passed via CMAKE_ARGS.
	${REINPLACE_CMD} -e '/BUILD_UNITTESTS/s|1|0|' \
		${PATCH_WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
