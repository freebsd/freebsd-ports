PORTNAME=	zanshin
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Daily organizer for KDE
WWW=		https://zanshin.kde.org/

LIB_DEPENDS=	libical.so:devel/libical

USES=		cmake compiler:c++14-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	calendarcore crash i18n parts runner windowsystem \
		ecm:build
# PIM Copmonents
USE_KDE+=	akonadi akonadicalendar kontactinterface \
		kdepim-runtime:run
USE_QT=		base
USE_XORG=	x11

.include <bsd.port.mk>
