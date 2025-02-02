PORTNAME=	kalarm
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Personal alarm scheduler
WWW=		https://www.kde.org/

LIB_DEPENDS=	libical.so:devel/libical \
		libvlc.so:multimedia/vlc

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 shebangfix tar:xz \
		xorg
USE_KDE=	auth bookmarks colorscheme codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kcmutils kio notifications \
		notifyconfig parts phonon service solid sonnet \
		statusnotifieritem texttemplate textwidgets unitconversion wallet \
		widgetsaddons windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime calendarcore calendarutils \
		contacts globalaccel grantleetheme holidays identitymanagement \
		idletime imap libkdepim mailcommon mailtransport mime \
		pimcommon pimtextedit \
		kdepim-runtime:run
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
