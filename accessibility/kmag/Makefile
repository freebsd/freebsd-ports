PORTNAME=	kmag
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	accessibility kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Screen magnifier
WWW=		https://www.kde.org/applications/utilities/kmag/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqaccessibilityclient-qt5.so:accessibility/libqaccessibilityclient@qt5

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons \
		i18n kio service widgetsaddons xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network printsupport widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
