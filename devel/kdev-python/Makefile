PORTNAME=	kdev-python
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python support for KDevelop
WWW=		https://www.kdevelop.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	kdev-pg-qt:devel/kdevelop-pg-qt
LIB_DEPENDS=	libKDevPlatformInterfaces.so:devel/kdevelop

USES=		cmake compiler:c++11-lib kde:5 python qt:5 tar:xz xorg
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		ecm i18n itemmodels jobwidgets kio newstuff parts service \
		solid sonnet syntaxhighlighting texteditor textwidgets \
		threadweaver widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

# Versioning values, to reduce plist churn (match with devel/kdevelop)
PLATFORM_VER=	511
PLIST_SUB+=	PLATFORM_VER=${PLATFORM_VER}

# Does not build with jobs.
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
