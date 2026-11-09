PORTNAME=	kmail-account-wizard
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE mail account wizard
WWW=		https://www.kde.org/

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake gettext-tools gl kde:6 \
		qt:6 tar:xz
USE_GL=		gl
# KDE Frameworks
USE_KDE=	codecs crash dbusaddons i18n kio mime \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi identitymanagement mailtransport
USE_QT=		base declarative
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
