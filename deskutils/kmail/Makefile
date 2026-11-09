PORTNAME=	kmail
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE mail client
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libqgpgmeqt6.so:security/qgpgme@qt6 \
		libqt6keychain.so:security/qtkeychain@qt6

RUN_DEPENDS=	accountwizard:deskutils/kmail-account-wizard \
		akonadiimportwizard:deskutils/akonadi-import-wizard \
		mboximporter:deskutils/mbox-importer \
		sieveeditor:deskutils/pim-sieve-editor

USES=		cmake cpe desktop-file-utils gettext-tools kde:6 \
		qt:6 tar:xz
CPE_VENDOR=	kde
# KDE Frameworks
USE_KDE=	calendarcore contacts crash dbusaddons guiaddons i18n \
		iconthemes itemviews jobwidgets kcmutils ktextaddons \
		mime notifications notifyconfig parts service sonnet \
		statusnotifieritem userfeedback xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicontacts akonadimime akonadisearch \
		calendarutils gravatar identitymanagement \
		kontactinterface ldap libkdepim libkleo libksieve \
		mailcommon mailtransport messagelib pimcommon \
		pimtextedit tnef
# KDE Plasma
USE_KDE+=	activities
USE_QT=		base declarative webengine
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
