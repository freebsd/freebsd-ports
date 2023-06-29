PORTNAME=	kdev-php
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PHP support for KDevelop
WWW=		https://www.kdevelop.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	kdev-pg-qt:devel/kdevelop-pg-qt
LIB_DEPENDS=	libKDevPlatformInterfaces.so:devel/kdevelop

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons ecm \
		i18n itemmodels jobwidgets kcmutils kio parts service solid \
		sonnet syntaxhighlighting texteditor textwidgets threadweaver \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network webkit widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

# Versioning values, to reduce plist churn (match with devel/kdevelop)
PLATFORM_VER=	511
PRIVATE_VER=	5.7
PLIST_SUB+=	PLATFORM_VER=${PLATFORM_VER} PRIVATE_VER=${PRIVATE_VER}

# Does not build with jobs.
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
