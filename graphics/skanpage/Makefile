PORTNAME=	skanpage
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multi-page image scanning application
WWW=		https://invent.kde.org/utilities/skanpage

# We pick GPLv3 out of 2|3|KDEeV
LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

BUILD_DEPENDS=	kquickimageeditor-qt6>=0:graphics/kquickimageeditor@qt6
RUN_DEPENDS=	kquickimageeditor-qt6>=0:graphics/kquickimageeditor@qt6

LIB_DEPENDS=	libKSaneCore6.so:graphics/ksanecore \
		libpng.so:graphics/png

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		i18n jobwidgets kio kirigami2 purpose service widgetsaddons \
		xmlgui \
		doctools:build ecm:build
USE_QT=		base pdf

OPTIONS_DEFINE=	OCR
OPTIONS_DEFAULT=	OCR

OCR_DESC=	Text recognition via Tesseract OCR
OCR_LIB_DEPENDS=	libleptonica.so:graphics/leptonica \
			libtesseract.so:graphics/tesseract

.include <bsd.port.mk>
