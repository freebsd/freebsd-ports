# $FreeBSD$

PORTNAME=	padthv1
DISTVERSIONPREFIX=	${PORTNAME}_
DISTVERSION=	0_8_6
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Old-school polyphonic additive synthesizer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libjack.so:audio/jack \
		liblo.so:audio/liblo

USES=		autoreconf gmake pkgconfig shared-mime-info
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	rncbc
USE_GL=		gl
USE_QT5=	core gui widgets xml buildtools_build qmake_build

PLIST_SUB=	SHL3=${PORTVERSION} SHL2=${PORTVERSION:R} SHL1=${PORTVERSION:R:R}

CONFIGURE_ARGS=	--disable-alsa-midi

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/padthv1.lv2/padthv1.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/padthv1.lv2/padthv1_ui.so

.include <bsd.port.mk>
