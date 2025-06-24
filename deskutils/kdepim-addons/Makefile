PORTNAME=	kdepim-addons
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM addons
WWW=		https://www.kde.org/

LICENSE=	LGPL21

BUILD_DEPENDS=	markdown:textproc/discount
RUN_DEPENDS=	markdown:textproc/discount
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libqgpgme.so:security/qgpgme@qt5

USES=		cmake compiler:c++11-lib gettext kde:6 pkgconfig qt:6 tar:xz \
		xorg
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		dbusaddons guiaddons i18n iconthemes itemmodels itemviews \
		jobwidgets kdeclarative kio parts prison service solid sonnet \
		syntaxhighlighting textwidgets wallet widgetsaddons \
		windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicalendar akonadicontacts akonadiimportwizard \
		akonadimime calendarcore calendarsupport \
		calendarutils contacts eventviews gapi grantleetheme gravatar \
		holidays identitymanagement imap incidenceeditor kaddressbook \
		kitinerary kontactinterface kpkpass libkdepim libkleo \
		libksieve mailcommon mailimporter mailtransport messagelib \
		mime pimcommon pimtextedit tnef
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
