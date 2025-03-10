PORTNAME=	kdev-php
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PHP support for KDevelop
WWW=		https://www.kdevelop.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	kdev-pg-qt:devel/kdevelop-pg-qt
LIB_DEPENDS=	libKDevPlatformInterfaces.so:devel/kdevelop

USES=		cmake compiler:c++11-lib kde:6 qt:6 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons i18n \
		itemmodels jobwidgets kcmutils kio parts service solid sonnet \
		syntaxhighlighting texteditor textwidgets threadweaver \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

# Versioning values, to reduce plist churn (match with devel/kdevelop)
.include "${.CURDIR}/../kdevelop/kdevelop.mk"

# Does not build with jobs.
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
