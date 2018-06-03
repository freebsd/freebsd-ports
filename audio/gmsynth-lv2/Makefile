# $FreeBSD$

PORTNAME=	gmsynth
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General MIDI LV2 Synth

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to compile: unknown FP unit 'sse'
BROKEN_armv7=		fails to compile: unknown FP unit 'sse'

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

.include <bsd.port.mk>
