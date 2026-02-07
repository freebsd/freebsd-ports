PORTNAME=	jacktrip
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.1
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
USE_QT=		base declarative networkauth positioning svg webchannel webengine websockets
USE_GL=		gl

USE_GITHUB=	yes
GH_TUPLE=	jothepro:doxygen-awesome-css:9380569:jothepro_doxygen_awesome_css/externals/doxygen-awesome-css \
		x42:weakjack:cddbeec0953d68048d164c472c9b30a5d96778db:x42_weakjack/externals/weakjack

# workaround for https://github.com/jacktrip/jacktrip/issues/1381
CXXFLAGS+=	`pkg-config --cflags rtaudio Qt6QuickControls2 Qt6Svg Qt6WebChannel Qt6WebEngineCore Qt6WebEngineQuick`
LDFLAGS+=	`pkg-config --libs rtaudio Qt6QuickControls2 Qt6Svg Qt6WebChannel Qt6WebEngineCore Qt6WebEngineQuick`

PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	git=false

.include <bsd.port.mk>
