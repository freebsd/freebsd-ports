# $FreeBSD$

PORTNAME=	guitarix
DISTVERSION=	0.37.1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/
PKGNAMESUFFIX=	-lv2
DISTNAME=	${PORTNAME}2-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Virtual versatile amplification for Jack and set of LV2 plugins

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3 \
		ladspa>0:audio/ladspa # https://sourceforge.net/p/guitarix/bugs/61/
LIB_DEPENDS=	libavahi-common.so:net/avahi-app \
		libboost_system.so:devel/boost-libs \
		libfftw3f.so:math/fftw3-float \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		liblilv-0.so:audio/lilv \
		liblrdf.so:textproc/liblrdf \
		libserd-0.so:devel/serd \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom \
		libzita-convolver.so:audio/zita-convolver \
		libzita-resampler.so:audio/zita-resampler

USES=		eigen:3 libarchive localbase:ldflags pkgconfig \
		python:build readline waf tar:xz
USE_GNOME=	atkmm cairo gtk20 gtkmm24 pangomm
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-lfs --ldflags="${LDFLAGS}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
BINARY_ALIAS=	python=${PYTHON_CMD}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_USE=	GNOME=intltool

post-stage: # https://sourceforge.net/p/guitarix/bugs/60/
	@${RM} -r ${STAGEDIR}/applications

.include <bsd.port.mk>
