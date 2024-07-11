PORTNAME=	ktextaddons
DISTVERSION=	1.5.4
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Various text handling addons
WWW=		https://invent.kde.org/libraries/ktextaddons/

LICENSE=	LGPL20+

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain

USES=		cmake kde:5 qt:5 tar:xz xorg
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		i18n jobwidgets kio service solid sonnet syntaxhighlighting \
		widgetsaddons windowsystem \
		ecm:build
USE_QT=		core concurrent dbus gui network speech widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

PLIST_SUB+=	LIBVERSION=${PORTVERSION}

.include <bsd.port.mk>
