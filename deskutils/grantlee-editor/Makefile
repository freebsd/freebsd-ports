PORTNAME=	grantlee-editor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Editor for Grantlee themes
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libqgpgmeqt6.so:security/qgpgme@qt6

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	archive attica auth codecs completion config configwidgets \
		coreaddons crash dbusaddons i18n itemmodels jobwidgets kio \
		newstuff service solid syntaxhighlighting texteditor \
		widgetsaddons windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime contacts grantleetheme \
		libkleo messagelib mime pimcommon pimtextedit
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
