PORTNAME=	ausweisapp2
DISTVERSION=	2.4.0
CATEGORIES=	deskutils security
MASTER_SITES=	https://github.com/Governikus/AusweisApp/releases/download/${DISTVERSION}/
DISTNAME=	AusweisApp-${DISTVERSION}

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Official authentication app for German ID cards and residence permits
WWW=		https://www.ausweisapp.bund.de/en/

LICENSE=	EUPL12
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libhttp_parser.so:www/http-parser \
		libpcsclite.so:devel/pcsc-lite \
		libudev.so:devel/libudev-devd

USES=		cmake compiler:c++17-lang gl pkgconfig qmake qt:6 ssl
USE_GL=		opengl
USE_QT=		base declarative scxml svg tools websockets

# The VENDOR variable controls the name of the directory in ${PREFIX}/share.
CMAKE_ARGS=	-DVENDOR=${PORTNAME}
MAKE_ENV=	DESTDIR=${STAGEDIR}

.include <bsd.port.mk>
