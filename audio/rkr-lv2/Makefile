# $FreeBSD$

PORTNAME=	rkr
DISTVERSIONPREFIX=	beta_
DISTVERSION=	2-2
DISTVERSIONSUFFIX=	-gd8c17d3
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rakarrack effects as LV2 plugins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libsamplerate.so:audio/libsamplerate

USES=		cmake:outsource pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ssj71
GH_PROJECT=	${PORTNAME}lv2

DATADIR=	${PREFIX}/share/${PORTNAME}.lv2

.include <bsd.port.mk>
