# $FreeBSD$

PORTNAME=	umbrello
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	UML modeller for KDE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake compiler:c++11-lang desktop-file-utils gnome kde:5 qt:5 tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm guiaddons i18n iconthemes init itemviews \
		jobwidgets kdelibs4support kio notifications parts service \
		solid sonnet texteditor textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network printsupport svg webkit widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

post-patch:
# The CMakeFile  sets BUILD_UNITTESTS to 1, not respecting the
# value passed via CMAKE_ARGS.
	${REINPLACE_CMD} -e '/BUILD_UNITTESTS/s|1|0|' \
		${PATCH_WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
