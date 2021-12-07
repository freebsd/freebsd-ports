PORTNAME=	guitarix
DISTVERSION=	0.43.0
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/
PKGNAMESUFFIX=	-lv2
DISTNAME=	${PORTNAME}2-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Virtual versatile amplification for Jack and set of LV2 plugins

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		faust:audio/faust \
		${LOCALBASE}/include/fftw3.h:math/fftw3 \
		roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf \
		sassc:textproc/sassc \
		ladspa>0:audio/ladspa # https://sourceforge.net/p/guitarix/bugs/61/
LIB_DEPENDS=	libavahi-common.so:net/avahi-app \
		libboost_system.so:devel/boost-libs \
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
		libzita-convolver.so:audio/zita-convolver \
		libzita-resampler.so:audio/zita-resampler
RUN_DEPENDS=	roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf

USES=		compiler:c++11-lang eigen:3 gnome libarchive localbase:ldflags \
		pkgconfig python:build readline shebangfix waf xorg tar:xz
USE_GNOME=	atkmm cairo gtk30 gtkmm30 gdkpixbuf2 pangomm
USE_XORG=	x11
USE_LDCONFIG=	yes
USE_BINUTILS=	yes # linking needs some GNU features, fails on 12 without this, see https://github.com/brummer10/GxPlugins.lv2/issues/9

SHEBANG_FILES=	tools/coverage tools/dsp2cc tools/dsp2insert tools/dsp2insert tools/tube_transfer.py # see https://github.com/brummer10/guitarix/issues/97

CONFIGURE_ARGS=	--enable-lfs --ldflags="${LDFLAGS}" --jack-session

LDFLAGS+=	-B${LOCALBASE}/bin # Use ld provided by USE_BINUTILS for GNU features, otherwise GNU ld isn't called

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD} ld=${LOCALBASE}/bin/ld

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_USE=	GNOME=intltool

post-install:
	# strip, see https://sourceforge.net/p/guitarix/bugs/60/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/guitarix
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}
	# workaround for https://github.com/brummer10/guitarix/issues/98
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo && \
	 ${MV} ${STAGEDIR}/usr/share/metainfo/org.guitarix.guitarix.metainfo.xml ${STAGEDIR}${PREFIX}/share/metainfo && \
	 ${RMDIR} ${STAGEDIR}/usr/share/metainfo ${STAGEDIR}/usr/share

.include <bsd.port.mk>
