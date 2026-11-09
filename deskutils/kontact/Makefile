PORTNAME=	kontact
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Personal Information Manager
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	crash dbusaddons guiaddons i18n iconthemes kcmutils \
		ktextaddons \
		ecm:build
# KDE PIM
USE_KDE+=	grantleetheme kontactinterface libkdepim pimcommon
USE_QT=		base declarative webengine
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
