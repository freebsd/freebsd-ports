PORTNAME=	ausweisapp2
DISTVERSION=	1.22.2
CATEGORIES=	deskutils security

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Official authentication app for German ID cards and residence permits

LICENSE=	EUPLv1.2
LICENSE_NAME=	European Union Public Licence V. 1.2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	pcsc-lite>0:devel/pcsc-lite
LIB_DEPENDS=	libhttp_parser.so:www/http-parser \
		libpcsclite.so:devel/pcsc-lite \
		libudev.so:devel/libudev-devd

USES=		cmake compiler:c++17-lang pkgconfig qmake qt:5 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Governikus
GH_PROJECT=	AusweisApp2
USE_QT=		concurrent core declarative gui network quickcontrols2 svg \
		websockets widgets buildtools_build linguisttools_build

# The VENDOR variable controls the name of the directory in ${PREFIX}/share.
CMAKE_ARGS=	-DVENDOR=${PORTNAME}
MAKE_ENV=	DESTDIR=${STAGEDIR}

.include <bsd.port.mk>
