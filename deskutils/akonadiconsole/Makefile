PORTNAME=	akonadiconsole
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Akonadi management and debugging console
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libassuan.so:security/libassuan  \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libqgpgmeqt6.so:security/qgpgme@qt6 \
		libical.so:devel/libical \
		libxapian.so:databases/xapian-core

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kio notifications parts \
		service solid sonnet textwidgets unitconversion widgetsaddons \
		windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicalendar akonadicontacts akonadimime \
		akonadisearch calendarcore calendarsupport contacts \
		grantleetheme identitymanagement libkdepim libkleo messagelib \
		mime pimcommon pimtextedit
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
