PORTNAME=	pim-sieve-editor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mail sieve editor
WWW=		https://www.kde.org/

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs config configwidgets coreaddons crash \
		dbusaddons i18n iconthemes kio service wallet \
		widgetsaddons xmlgui \
		ecm:build
# pim components
USE_KDE+=	libksieve mailtransport pimcommon pimtextedit
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
