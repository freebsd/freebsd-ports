PORTNAME=	jacktrip
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-machine audio network performance over the Internet
WWW=		https://github.com/jacktrip/jacktrip

LICENSE=	MIT GPLv3
LICENSE_COMB=	multi

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libjack.so:audio/jack \
		librtaudio.so:audio/rtaudio

USES=		cmake compiler:c++17-lang gl localbase:ldflags pkgconfig qt:6
USE_QT=		base declarative networkauth positioning svg webchannel websockets
USE_GL=		gl

USE_GITHUB=	yes
GH_TUPLE=	jothepro:doxygen-awesome-css:9380569:jothepro_doxygen_awesome_css/externals/doxygen-awesome-css \
		x42:weakjack:cddbeec0953d68048d164c472c9b30a5d96778db:x42_weakjack/externals/weakjack

# workaround for https://github.com/jacktrip/jacktrip/issues/1381
_PC_MODULES=	rtaudio Qt6QuickControls2 Qt6Svg Qt6WebChannel
CXXFLAGS+=	`pkg-config --cflags ${_PC_MODULES}`
LDFLAGS+=	`pkg-config --libs ${_PC_MODULES}`

PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=		WEBENGINE
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_armv7=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE
OPTIONS_DEFAULT_powerpc64le=	WEBENGINE

WEBENGINE_DESC=		Virtual Studio mode (requires QtWebEngine)
WEBENGINE_USE=		QT=webengine
WEBENGINE_VARS=		_PC_MODULES+=Qt6WebEngineCore _PC_MODULES+=Qt6WebEngineQuick

post-patch-WEBENGINE-off:
	${REINPLACE_CMD} -e 's/^set(novs FALSE)/set(novs TRUE)/' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
