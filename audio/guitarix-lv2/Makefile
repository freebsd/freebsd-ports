PORTNAME=	guitarix
DISTVERSIONPREFIX=	V
DISTVERSION=	0.46.0
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Virtual versatile amplification for Jack and set of LV2 plugins
WWW=		https://guitarix.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		faust:audio/faust \
		${LOCALBASE}/include/fftw3.h:math/fftw3 \
		roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf \
		sassc:textproc/sassc \
		ladspa>0:audio/ladspa # https://sourceforge.net/p/guitarix/bugs/61/
LIB_DEPENDS=	libavahi-common.so:net/avahi-app \
		libboost_thread.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libfftw3f.so:math/fftw3-float \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjack.so:audio/jack \
		liblilv-0.so:audio/lilv \
		liblo.so:audio/liblo \
		liblrdf.so:textproc/liblrdf \
		libserd-0.so:devel/serd \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom \
		libwayland-client.so:graphics/wayland \
		libzita-convolver.so:audio/zita-convolver \
		libzita-resampler.so:audio/zita-resampler
RUN_DEPENDS=	roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf

USES=		compiler:c++11-lang gnome libarchive localbase:ldflags \
		pkgconfig python:build readline shebangfix waf xorg ssl tar:xz
USES+=		eigen:3 # shouldn't be needed, see https://github.com/brummer10/guitarix/issues/210
USE_GNOME=	atkmm cairo gtk30 gtkmm30 pangomm
USE_XORG=	x11
USE_LDCONFIG=	yes
USE_BINUTILS=	yes # linking needs some GNU features, fails on 12 without this, see https://github.com/brummer10/GxPlugins.lv2/issues/9

USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_TUPLE=	enyojs:bootplate:a11645b:bootplate/webui/bootplate \
		sdatkinson:NeuralAmpModelerCore:74a07ce222fac3e681e7c2c2cb515d53c4e272b4:namc/src/NAM/NeuralAmpModelerCore \
		jatinchowdhury18:RTNeural:0b0e5d0:rtn/src/RTNeural/RTNeural

                #xtensor-stack:xsimd:a00c81f7b9e808a42aedcf7da2fbb1f9a636da34:xtensor_stack_xsimd/trunk/src/RTNeural/RTNeural/modules/xsimd \
                #brummer10:../enyojs/enyo:5417c8fe7e2ffa7154dc3e7e67612858d0923cd1:brummer10___/enyojs/enyo/trunk/webui/bootplate/enyo \
                #brummer10:../enyojs/onyx:7ff3005b5b5e59bc0f9f3b3bd738c6019c12a83e:brummer10___/enyojs/onyx/trunk/webui/bootplate/lib/onyx \
                #brummer10:../enyojs/layout:1ba8f591ceedcca87ff461f35397478bf25f7c4b:brummer10___/enyojs/layout/trunk/webui/bootplate/lib/layout \


SHEBANG_FILES=	tools/coverage tools/dsp2cc tools/dsp2insert tools/dsp2insert tools/tube_transfer.py # see https://github.com/brummer10/guitarix/issues/97

CONFIGURE_ARGS=	--enable-lfs --ldflags="${LDFLAGS}" --jack-session

#CXXFLAGS+=	-I${LOCALBASE}/include/eigen3
CXXFLAGS+=	-I${WRKSRC}/src/RTNeural/RTNeural/modules/Eigen
LDFLAGS+=	-B${LOCALBASE}/bin # Use ld provided by USE_BINUTILS for GNU features, otherwise GNU ld isn't called

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
WRKSRC_SUBDIR=	trunk
BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD} ld=${LOCALBASE}/bin/ld

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_USE=	GNOME=intltool:build

post-patch:
	@${REINPLACE_CMD} -e 's/boost_system/boost_thread/' ${WRKSRC}/wscript

post-install:
	# strip, see https://sourceforge.net/p/guitarix/bugs/60/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/guitarix
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
