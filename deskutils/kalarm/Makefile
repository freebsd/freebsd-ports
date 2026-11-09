PORTNAME=	kalarm
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Personal alarm scheduler
WWW=		https://www.kde.org/

USES=		cmake gettext-tools kde:6 qt:6 shebangfix tar:xz \
		xorg
# KDE Frameworks
USE_KDE=	auth calendarcore codecs completion config \
		configwidgets contacts crash dbusaddons globalaccel \
		guiaddons holidays i18n iconthemes itemmodels \
		jobwidgets kio ktextaddons mime notifications \
		notifyconfig service statusnotifieritem textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicontacts akonadimime calendarutils \
		identitymanagement mailtransport
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
