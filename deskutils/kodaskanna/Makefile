PORTNAME=	kodaskanna
DISTVERSION=	0.1.0
CATEGORIES=	deskutils
MASTER_SITES=	KDE/unstable/${PORTNAME}/${DISTVERSION}/src

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Barcode and QR-code scanner

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libZXing.so.1:textproc/zxing-cpp

USES=		cmake compiler:c++17-lang gl kde:5 pkgconfig qt:5 tar:xz xorg
USE_GL=		gl
USE_XORG=	x11
USE_QT=		concurrent core dbus declarative gui \
		multimedia network quickcontrols quickcontrols2 \
		widgets xml \
		buildtools_build qmake_build
USE_KDE=	auth codecs config configwidgets coreaddons i18n \
		kio purpose service widgetsaddons windowsystem \
		ecm_build

.include <bsd.port.mk>
