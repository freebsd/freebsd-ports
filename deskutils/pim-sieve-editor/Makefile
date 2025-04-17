PORTNAME=	pim-sieve-editor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mail sieve editor
WWW=		https://www.kde.org/

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz
USE_KDE=	auth bookmarks codecs config configwidgets coreaddons crash \
		dbusaddons i18n iconthemes kio service userfeedback \
		wallet widgetsaddons xmlgui \
		ecm:build
# pim components
USE_KDE+=	libksieve mailtransport pimcommon pimtextedit
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
