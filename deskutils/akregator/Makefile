PORTNAME=	akregator
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Feed reader for KDE
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libqgpgmeqt6.so:security/qgpgme@qt6

USES=		cmake compiler:c++11-lib desktop-file-utils gettext kde:6 qt:6 \
		tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		i18n iconthemes itemmodels jobwidgets kcmutils kio \
		notifications notifyconfig parts service solid sonnet \
		statusnotifieritem texteditor textwidgets userfeedback \
		widgetsaddons windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadimime contacts grantleetheme kontactinterface \
		ktextaddons libkdepim libkleo messagelib mime pimcommon \
		pimtextedit syndication
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
