# $FreeBSD$

PORTNAME=	gmsynth
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General MIDI LV2 Synth

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
# FluidSynth is left bundled based on the project owner's request: https://github.com/x42/gmsynth.lv2/issues/2#issuecomment-441458303

USES=		gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	x42
GH_PROJECT=	${PORTNAME}.lv2
USE_GNOME=	glib20

PLIST_FILES=	lib/lv2/${PORTNAME}.lv2/GeneralUser_LV2.sf2 \
		lib/lv2/${PORTNAME}.lv2/${PORTNAME}.so \
		lib/lv2/${PORTNAME}.lv2/${PORTNAME}.ttl \
		lib/lv2/${PORTNAME}.lv2/manifest.ttl

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD

SIMD_MAKE_ENV=		PORT_SIMD_FLAGS="-msse -msse2 -mfpmath=sse"

.include <bsd.port.mk>
