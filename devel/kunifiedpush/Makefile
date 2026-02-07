PORTNAME=	kunifiedpush
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	UnifiedPush client library and distributor daemon for KDE
WWW=		https://invent.kde.org/libraries/kunifiedpush

USES=		cmake compiler:c++20-lang gettext kde:6 qt:6 ssl tar:xz
USE_KDE=	coreaddons i18n kcmutils service solid \
		ecm:build
USE_QT=		base declarative websockets

IGNORE_FreeBSD_13=	does not build with OpenSSL 1.1.1

.include <bsd.port.mk>
