# $FreeBSD$

PORTNAME=	kmail-account-wizard
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE mail account wizard

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake compiler:c++11-lib gettext  kde:5 qt:5 tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons crash \
		dbusaddons ecm i18n itemmodels itemviews kcmutils kio kross \
		newstuff notifications notifyconfig service texteditor wallet \
		widgetsaddons xmlgui
# pim components
USE_KDE+=	akonadi akonadimime identitymanagement ldap libkdepim libkleo \
		mailtransport mime pimcommon pimtextedit
USE_QT=		core dbus gui network script widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
