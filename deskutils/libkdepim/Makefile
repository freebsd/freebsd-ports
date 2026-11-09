PORTNAME=	libkdepim
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM Libraries
WWW=		https://community.kde.org/KDE_PIM/Akonadi

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	completion i18n widgetsaddons \
		ecm:build
USE_QT=		base tools:build

USE_LDCONFIG=	yes

.include <bsd.port.mk>
