PORTNAME=	spectacle
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0-1
DISTVERSIONSUFFIX=	-g27b1525
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Realtime graphical spectrum analyzer, LV2 plugin and JACK application

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash \
		${LOCALBASE}/include/fftw3.h:math/fftw3 \
		xxd:editors/vim-console
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		compiler:c++0x gl gmake gnome pkgconfig shebangfix xorg
USE_GNOME=	cairo
USE_GL=		gl
USE_XORG=	x11

SHEBANG_FILES=	dpf/utils/generate-ttl.sh

USE_GITHUB=	yes
GH_ACCOUNT=	jpcima
GH_TUPLE=	DISTRHO:DPF:4be6a2c:DISTRHO_DPF/dpf

CXXFLAGS+=	-I${FILESDIR}
LDFLAGS+=	-lpthread

OPTIONS_DEFINE=		JACK VST
OPTIONS_DEFAULT=	JACK
OPTIONS_SUB=		yes

JACK_MAKE_ARGS=		BUILD_JACK=true
JACK_MAKE_ARGS_OFF=	BUILD_JACK=false
JACK_LIB_DEPENDS=	libjack.so:audio/jack

VST_MAKE_ARGS=		BUILD_VST=true
VST_MAKE_ARGS_OFF=	BUILD_VST=false

.include <bsd.port.mk>
