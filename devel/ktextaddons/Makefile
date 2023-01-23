PORTNAME=	ktextaddons
DISTVERSION=	1.0.1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Various text handling addons
WWW=		https://invent.kde.org/libraries/ktextaddons

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain

USES=		cmake kde:5 qt:5 tar:xz
USE_KDE=	archive auth codecs config configwidgets coreaddons ecm i18n \
		widgetsaddons xmlgui
USE_QT=		core dbus gui network speech widgets xml \
		buildtools:build qmake:build

PLIST_SUB+=	LIBVERSION=${PORTVERSION}

.include <bsd.port.mk>
