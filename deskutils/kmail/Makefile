PORTNAME=	kmail
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE mail client
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libqgpgmeqt6.so:security/qgpgme@qt6 \
		libqt6keychain.so:security/qtkeychain@qt6

RUN_DEPENDS=	accountwizard:deskutils/kmail-account-wizard \
		akonadiimportwizard:deskutils/akonadi-import-wizard \
		mboximporter:deskutils/mbox-importer \
		sieveeditor:deskutils/pim-sieve-editor

USES=		cmake compiler:c++11-lib cpe desktop-file-utils gettext kde:6 \
		qt:6 tar:xz xorg
CPE_VENDOR=	kde
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons i18n iconthemes imap \
		itemmodels itemviews jobwidgets kcmutils kio notifications \
		notifyconfig parts service solid sonnet statusnotifieritem \
		syntaxhighlighting texteditor textwidgets unitconversion \
		userfeedback wallet widgetsaddons windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime akonadisearch calendarcore \
		calendarutils contacts grantleetheme gravatar \
		identitymanagement kontactinterface ktextaddons ldap \
		libkdepim libkleo libksieve mailcommon mailtransport \
		messagelib mime pimcommon pimtextedit tnef \
		kdepim-runtime:run
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
