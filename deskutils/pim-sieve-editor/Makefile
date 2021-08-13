PORTNAME=	pim-sieve-editor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mail sieve editor

DEPRECATED=	Uses EOL Python 2.7 via www/qt5-webengine
EXPIRATION_DATE=2021-06-23

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs config configwidgets coreaddons crash \
		dbusaddons i18n iconthemes kio service wallet \
		widgetsaddons xmlgui \
		ecm_build
# pim components
USE_KDE+=	libksieve mailtransport pimcommon
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr


OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
