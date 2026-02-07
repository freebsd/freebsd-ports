PORTNAME=	konversation
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	irc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	User friendly IRC client for KDE
WWW=		https://konversation.kde.org

LICENSE=	GPLv2+

LIB_DEPENDS=	libqca-qt6.so:devel/qca@qt6

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext kde:6 \
		qt:6 shebangfix tar:xz xorg \
		python:run
USE_KDE=	archive attica auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons doctools globalaccel \
		i18n iconthemes idletime itemviews jobwidgets kio newstuff \
		notifications notifyconfig parts phonon service solid sonnet \
		statusnotifieritem textwidgets wallet widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

SHEBANG_FILES=	data/scripts/bug \
		data/scripts/cmd \
		data/scripts/media \
		data/scripts/sayclip \
		data/scripts/sysinfo

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
