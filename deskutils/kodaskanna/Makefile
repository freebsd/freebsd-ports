PORTNAME=	kodaskanna
DISTVERSION=	0.2.2
CATEGORIES=	deskutils
MASTER_SITES=	KDE/unstable/${PORTNAME}/${DISTVERSION}/src

PATCH_SITES=	https://invent.kde.org/graphics/kodaskanna/-/commit/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Barcode and QR-code scanner
WWW=		https://apps.kde.org/kodaskanna/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libZXing.so:textproc/zxing-cpp

USES=		cmake compiler:c++17-lang gettext gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		opengl
USE_QT=		base tools:build
USE_KDE=	config configwidgets coreaddons i18n \
		kio purpose service widgetsaddons \
		ecm:build

.include <bsd.port.mk>
