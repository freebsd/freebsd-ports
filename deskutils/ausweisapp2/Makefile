PORTNAME=	ausweisapp2
DISTVERSION=	2.1.1
CATEGORIES=	deskutils security

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Official authentication app for German ID cards and residence permits
WWW=		https://www.ausweisapp.bund.de/ausweisapp2/

LICENSE=	EUPLv1.2
LICENSE_NAME=	European Union Public Licence V. 1.2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	libglvnd>0:graphics/libglvnd \
		pcsc-lite>0:devel/pcsc-lite \
		qt5-declarative-test>0:x11-toolkits/qt5-declarative-test

LIB_DEPENDS=	libhttp_parser.so:www/http-parser \
		libpcsclite.so:devel/pcsc-lite \
		libudev.so:devel/libudev-devd

USES=		cmake compiler:c++17-lang pkgconfig qmake qt:6 ssl
USE_GL+=	gl opengl
USE_GITHUB=	yes
GH_ACCOUNT=	Governikus
GH_PROJECT=	AusweisApp
USE_QT=		base connectivity declarative scxml shadertools svg tools \
		websockets

# The VENDOR variable controls the name of the directory in ${PREFIX}/share.
CMAKE_ARGS=	-DVENDOR=${PORTNAME}
MAKE_ENV=	DESTDIR=${STAGEDIR}

.include <bsd.port.mk>
