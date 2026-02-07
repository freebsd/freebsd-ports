PORTNAME=	kalarm
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Personal alarm scheduler
WWW=		https://www.kde.org/

LIB_DEPENDS=	libical.so:devel/libical

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
OPTIONS_RADIO=		AUDIO
AUDIO_DESC=		Audio backend
OPTIONS_RADIO_AUDIO=	MPV VLC
OPTIONS_DEFAULT=	MPV # VLC still uses Qt5
OPTIONS_SUB=		yes

MPV_DESC=		Play audio via libmpv
MPV_LIB_DEPENDS=	libmpv.so:multimedia/mpv
MPV_CMAKE_BOOL=		ENABLE_LIBMPV

VLC_DESC=		Play audio via libVLC
VLC_LIB_DEPENDS=	libvlc.so:multimedia/vlc
VLC_CMAKE_BOOL=		ENABLE_LIBVLC

.include <bsd.port.mk>
