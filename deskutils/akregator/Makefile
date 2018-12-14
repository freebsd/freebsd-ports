# $FreeBSD$

PORTNAME=	akregator
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A Feed Reader by KDE

LICENSE=	LGPL21

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake:outsource compiler:c++11-lib gettext grantlee:5 kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		ecm i18n iconthemes itemmodels jobwidgets kcmutils kio \
		notifications notifyconfig parts service sonnet texteditor\
		textwidgets widgetsaddons xmlgui
# pim components
USE_KDE+=	akonadi akonadimime contacts grantleetheme kontactinterface \
		libkdepim libkleo messagelib mime pimcommon pimtextedit syndication
USE_QT=		core dbus declarative gui location network printsupport \
		webchannel webengine widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr


OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
