PORTNAME=	toneshifteq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	12-band equalizer LV2 plugin for mixing and mastering
WWW=		https://github.com/brummer10/ToneShiftEQ

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		xxd:sysutils/xxd
LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float

USES=		compiler:c++17-lang gmake gnome localbase pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	x11
USE_BINUTILS=	yes # linking needs some GNU features, fails on 12 without this, see https://github.com/brummer10/GxPlugins.lv2/issues/9

USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	ToneShiftEQ
GH_TUPLE=	brummer10:libxputty:7a6aa4a:libxputty/libxputty

MAKEFILE=	makefile

ALL_TARGET=	clap lv2
INSTALL_TARGET=	install

MAKE_ARGS=	LV2_INSTALL_DIR="${PREFIX}/lib/lv2" \
		EXE_INSTALL_DIR="${PREFIX}/bin" \
		CLAP_INSTAL_DIR="${PREFIX}/lib/clap"

PLIST_FILES=	lib/clap/toneshifteq.clap \
		lib/lv2/ToneShiftEQ.lv2/manifest.ttl \
		lib/lv2/ToneShiftEQ.lv2/toneshifteq.so \
		lib/lv2/ToneShiftEQ.lv2/toneshifteq.ttl \
		lib/lv2/ToneShiftEQ.lv2/toneshifteq_ui.so

.include <bsd.port.mk>
