PORTNAME=	mbox-importer
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Import mbox files to KMail
WWW=		https://invent.kde.org/pim/mbox-importer

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme

USES=		cmake desktop-file-utils gettext-tools kde:6 qt:6 \
		tar:xz
# KDE Frameworks
USE_KDE=	config crash i18n service \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi identitymanagement mailcommon mailimporter
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
