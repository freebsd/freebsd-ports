PORTNAME=	cervisia
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	CVS Frontend for KDE

DEPRECATED=	Abandoned and excluded from future KDE Gear releases
EXPIRATION_DATE=	2025-08-31

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 \
		qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons doctools i18n iconthemes init itemviews jobwidgets \
		kdesu kio notifications parts pty service solid sonnet \
		textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
