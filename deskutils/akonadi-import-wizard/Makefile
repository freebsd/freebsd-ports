PORTNAME=	akonadi-import-wizard
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Import data from other mail clients to KMail
WWW=		https://www.kde.org/

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	archive config contacts crash dbusaddons i18n \
		iconthemes kio \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi identitymanagement mailcommon mailimporter \
		mailtransport messagelib pimcommon
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
