PORTNAME=	skanpage
DISTVERSION=	1.0.0
CATEGORIES=	graphics kde
MASTER_SITES=	https://download.kde.org/stable/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Multi-page image scanning application

# We pick GPLv3 out of 2|3|KDEeV
LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

LIB_DEPENDS=	libKF5Sane.so:graphics/libksane \
		libpng.so:graphics/png

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth config configwidgets codecs completion \
		coreaddons i18n jobwidgets kio kirigami2 \
		service widgetsaddons xmlgui \
		doctools_build ecm_build
USE_QT=		core concurrent dbus gui network widgets xml \
		buildtools_build qmake_build testlib_build

.include <bsd.port.mk>
