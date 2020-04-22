# $FreeBSD$

PORTNAME=	spectacle
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
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

USES=		compiler:c++0x gmake gnome pkgconfig shebangfix xorg
SHEBANG_FILES=	dpf/utils/generate-ttl.sh
USE_GITHUB=	yes
GH_ACCOUNT=	jpcima
GH_TUPLE=	DISTRHO:DPF:93e070c6d3c98b7bcbcbd4f01e76e1ba229bb6ae:DISTRHO_DPF/dpf
USE_GNOME=	cairo
USE_XORG=	x11

CXXFLAGS+=	-I${FILESDIR}
LDFLAGS+=	-lpthread

OPTIONS_DEFINE=		JACK
OPTIONS_DEFAULT=	JACK
OPTIONS_SUB=		yes

JACK_MAKE_ARGS=		BUILD_JACK=true
JACK_MAKE_ARGS_OFF=	BUILD_JACK=false
JACK_LIB_DEPENDS=	libjack.so:audio/jack

.include <bsd.port.mk>
