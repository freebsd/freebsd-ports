PORTNAME=	kodaskanna
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	KDE/unstable/${PORTNAME}/${DISTVERSION}/src

PATCH_SITES=	https://invent.kde.org/graphics/kodaskanna/-/commit/
PATCHFILES=	1656f7e66aec20ecd4a66f041bd7fc1850721e08.diff:-p1

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Barcode and QR-code scanner
WWW=		https://invent.kde.org/graphics/kodaskanna

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libZXing.so:textproc/zxing-cpp

USES=		cmake compiler:c++17-lang gl kde:5 pkgconfig qt:5 tar:xz xorg
USE_GL=		gl
USE_XORG=	x11
USE_QT=		concurrent core dbus declarative gui \
		multimedia network quickcontrols quickcontrols2 \
		widgets xml \
		buildtools:build qmake:build
USE_KDE=	auth codecs config configwidgets coreaddons i18n \
		kio purpose service widgetsaddons windowsystem \
		ecm:build

.include <bsd.port.mk>
