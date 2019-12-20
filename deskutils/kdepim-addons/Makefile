# $FreeBSD$

PORTNAME=	kdepim-addons
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM addons

LICENSE=	LGPL21

BUILD_DEPENDS=	markdown:textproc/discount
RUN_DEPENDS=	markdown:textproc/discount
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake compiler:c++11-lib gettext grantlee:5 kde:5 \
		pkgconfig qt:5 tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		dbusaddons ecm i18n iconthemes itemmodels itemviews jobwidgets \
		kdeclarative khtml kio prison service sonnet syntaxhighlighting \
		textwidgets wallet widgetsaddons xmlgui
# pim components
USE_KDE+=	akonadi akonadicalendar akonadicontacts akonadiimportwizard \
		akonadimime akonadinotes calendarcore calendarsupport \
		calendarutils contacts eventviews gapi grantleetheme \
		gravatar identitymanagement imap incidenceeditor \
		kdepim-apps-libs kitinerary kontactinterface kpkpass libkdepim \
		libkleo libksieve mailcommon mailimporter mailtransport \
		messagelib mime pimcommon pimtextedit tnef
USE_QT=		concurrent core dbus declarative gui location network printsupport testlib \
		webchannel webengine widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
