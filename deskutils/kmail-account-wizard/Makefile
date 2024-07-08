PORTNAME=	kmail-account-wizard
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE mail account wizard
WWW=		https://www.kde.org/

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt@qt5

USES=		cmake compiler:c++11-lib desktop-file-utils gettext gl kde:5 \
		qt:5 shared-mime-info tar:xz
USE_GL=		gl
USE_KDE=	attica auth codecs config configwidgets coreaddons crash \
		dbusaddons i18n itemmodels itemviews kcmutils kio kross \
		newstuff notifications notifyconfig service texteditor wallet \
		widgetsaddons xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadimime identitymanagement ldap libkdepim libkleo \
		mailtransport mime pimcommon pimtextedit
USE_QT=		concurrent core dbus gui network script widgets xml \
		buildtools:build qmake:build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
