PORTNAME=	pim-sieve-editor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mail sieve editor
WWW=		https://invent.kde.org/pim/pim-sieve-editor

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	bookmarks coreaddons crash dbusaddons i18n iconthemes \
		kio ktextaddons userfeedback windowsystem xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	imap libksieve mailtransport pimcommon
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
