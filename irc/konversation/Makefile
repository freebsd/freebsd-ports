PORTNAME=	konversation
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	irc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	User friendly IRC client for KDE

LICENSE=	GPLv2+

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext kde:5 \
		python:run qca qt:5 shebangfix tar:xz
USE_KDE=	archive attica auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons doctools \
		emoticons globalaccel i18n iconthemes idletime itemviews \
		jobwidgets kio newstuff notifications notifyconfig parts service solid \
		sonnet textwidgets wallet widgetsaddons windowsystem xmlgui \
		ecm_build \
		init_run
USE_QT=		concurrent core dbus gui multimedia network phonon4 widgets xml \
		buildtools_build qmake_build

SHEBANG_FILES=	data/scripts/bug \
		data/scripts/cmd \
		data/scripts/media \
		data/scripts/sayclip \
		data/scripts/sysinfo \
		data/updaters/*.pl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
