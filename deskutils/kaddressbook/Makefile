PORTNAME=	kaddressbook
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE contact manager
WWW=		https://www.kde.org/

USES=		cmake desktop-file-utils gettext-tools kde:6 qt:6 \
		tar:xz
# KDE Frameworks
USE_KDE=	colorscheme coreaddons crash dbusaddons i18n iconthemes \
		kcmutils ktextaddons userfeedback \
		doctools:build ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicontacts akonadisearch grantleetheme \
		kontactinterface ldap libkdepim pimcommon
# KDE Plasma
USE_KDE+=	activities
USE_QT=		base declarative
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
