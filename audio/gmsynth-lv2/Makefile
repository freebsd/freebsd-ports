# $FreeBSD$

PORTNAME=	gmsynth
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General MIDI LV2 Synth

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	x42
GH_PROJECT=	${PORTNAME}.lv2
USE_GNOME=	glib20

PLIST_FILES=	lib/lv2/${PORTNAME}.lv2/GeneralUser_LV2.sf2 \
		lib/lv2/${PORTNAME}.lv2/${PORTNAME}.so \
		lib/lv2/${PORTNAME}.lv2/${PORTNAME}.ttl \
		lib/lv2/${PORTNAME}.lv2/manifest.ttl

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	SSE

SSE_MAKE_ENV=		PORT_SIMD_FLAGS="-msse -msse2 -mfpmath=sse"

.include <bsd.port.mk>
