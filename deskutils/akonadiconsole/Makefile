PORTNAME=	akonadiconsole
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Akonadi management and debugging console
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libical.so:devel/libical \
		libxapian.so:databases/xapian-core

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	calendarcore completion config contacts crash \
		dbusaddons i18n itemmodels itemviews kio mime \
		textwidgets widgetsaddons xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicontacts akonadimime akonadisearch \
		calendarsupport libkdepim messagelib
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
