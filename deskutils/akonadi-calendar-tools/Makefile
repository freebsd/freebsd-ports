PORTNAME=	akonadi-calendar-tools
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	CLI tools to manage akonadi calendars
WWW=		https://www.kde.org/

LIB_DEPENDS=	libical.so:devel/libical

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	calendarcore i18n \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicalendar calendarsupport
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
