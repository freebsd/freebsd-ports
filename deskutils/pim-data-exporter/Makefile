PORTNAME=	pim-data-exporter
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Import and export KDE PIM data
WWW=		https://invent.kde.org/pim/pim-data-exporter

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	archive calendarcore contacts coreaddons crash \
		dbusaddons i18n itemviews kio ktextaddons mime \
		notifications statusnotifieritem userfeedback \
		widgetsaddons xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi identitymanagement mailcommon mailtransport \
		pimcommon
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
