PORTNAME=	ktextaddons
DISTVERSION=	1.7.0
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Various text handling addons
WWW=		https://invent.kde.org/libraries/ktextaddons/

LICENSE=	LGPL20+

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

USES=		gettext cmake kde:6 qt:6 tar:xz xorg
USE_KDE=	archive coreaddons colorscheme i18n kio sonnet \
		syntaxhighlighting textwidgets widgetsaddons \
		ecm:build
USE_QT=		base speech
USE_XORG=	x11

PLIST_SUB+=	LIBVERSION=${PORTVERSION}

.include <bsd.port.mk>
