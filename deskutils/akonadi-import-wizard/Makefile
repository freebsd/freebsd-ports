PORTNAME=	akonadi-import-wizard
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Import data from other mail clients to KMail
WWW=		https://www.kde.org/

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libqgpgmeqt6.so:security/qgpgme@qt6 \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		crash dbusaddons i18n itemmodels kio service texttemplate \
		wallet widgetsaddons xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime contacts grantleetheme \
		identitymanagement imap libkdepim libkleo mailcommon \
		mailimporter mailtransport messagelib mime pimcommon \
		pimtextedit
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
