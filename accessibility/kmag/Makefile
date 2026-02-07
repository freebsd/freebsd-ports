PORTNAME=	kmag
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	accessibility kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Screen magnifier
WWW=		https://www.kde.org/applications/utilities/kmag/

LICENSE=	GPLv2

LIB_DEPENDS=	libqaccessibilityclient-qt6.so:accessibility/libqaccessibilityclient@qt6

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons i18n kio service \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
