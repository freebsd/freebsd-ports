PORTNAME=	skanpage
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multi-page image scanning application

# We pick GPLv3 out of 2|3|KDEeV
LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

LIB_DEPENDS=	libKSaneCore.so:graphics/ksanecore \
		libpng.so:graphics/png

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth config configwidgets codecs completion \
		coreaddons crash i18n jobwidgets kio kirigami2 purpose \
		service widgetsaddons xmlgui \
		doctools_build ecm_build
USE_QT=		core concurrent dbus declarative gui network printsupport \
		quickcontrols2 widgets xml \
		buildtools_build qmake_build testlib_build




.include <bsd.port.mk>
