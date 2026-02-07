PORTNAME=	kdesdk-thumbnailers
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE thumbnail generator for gettext po files
WWW=		https://www.kde.org/

LIB_DEPENDS=	libgettextpo.so:devel/gettext-tools

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	completion config coreaddons i18n jobwidgets kio service solid \
		widgetsaddons windowsystem \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
