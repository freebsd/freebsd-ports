# $FreeBSD$

PORTNAME=	akonadi-import-wizard
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Import data from other mail clients to KMail

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		crash dbusaddons ecm i18n itemmodels kio service wallet \
		widgetsaddons xmlgui
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime contacts identitymanagement \
		imap libkdepim libkleo mailcommon mailimporter mailtransport \
		messagelib mime pimcommon pimtextedit
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
