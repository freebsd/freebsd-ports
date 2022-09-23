PORTNAME=	kde-dev-utils
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE development utilities

USES=		compiler:c++11-lang cmake desktop-file-utils gl kde:5 \
		qt:5 tar:xz xorg
USE_GL=		gl
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons i18n itemviews jobwidgets kio parts service \
		solid sonnet textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus designer gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
