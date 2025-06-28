PORTNAME=	ausweisapp2
DISTVERSION=	2.3.2
CATEGORIES=	deskutils security

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Official authentication app for German ID cards and residence permits
WWW=		https://www.ausweisapp.bund.de/ausweisapp2/

LICENSE=	EUPL12
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libhttp_parser.so:www/http-parser \
		libpcsclite.so:devel/pcsc-lite \
		libudev.so:devel/libudev-devd

USES=		cmake compiler:c++17-lang gl pkgconfig qmake qt:6 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Governikus
GH_PROJECT=	AusweisApp
USE_GL=		opengl
USE_QT=		base declarative scxml shadertools svg tools websockets

# The VENDOR variable controls the name of the directory in ${PREFIX}/share.
CMAKE_ARGS=	-DVENDOR=${PORTNAME}
MAKE_ENV=	DESTDIR=${STAGEDIR}

.include <bsd.port.mk>
