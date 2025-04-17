PORTNAME=	kdev-php
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PHP support for KDevelop
WWW=		https://www.kdevelop.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	kdev-pg-qt:devel/kdevelop-pg-qt
LIB_DEPENDS=	libKDevPlatformInterfaces.so:devel/kdevelop

USES=		cmake compiler:c++17-lang gettext-tools gl kde:6 qt:6 \
		tar:xz xorg
USE_GL=		gl opengl # GLX
USE_KDE=	colorscheme completion config configwidgets coreaddons i18n \
		jobwidgets kio parts service solid syntaxhighlighting \
		texteditor threadweaver widgetsaddons xmlgui \
		ecm:build
USE_QT=		5compat base declarative positioning webchannel webengine
USE_XORG=	x11

# Versioning values, to reduce plist churn (match with devel/kdevelop)
.include "${.CURDIR}/../kdevelop/kdevelop.mk"

.include <bsd.port.mk>
