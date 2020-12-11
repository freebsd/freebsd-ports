# $FreeBSD$

PORTNAME=	webrtc-audio-processing
DISTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	https://freedesktop.org/software/pulseaudio/${PORTNAME}/

PATCH_SITES=	https://gitlab.freedesktop.org/pulseaudio/${PORTNAME}/-/commit/
PATCHFILES+=	2083c9a5dd34.diff:-p1 # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/merge_requests/6
PATCHFILES+=	3f9907f93d39.diff:-p1 # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/merge_requests/13

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	AudioProcessing module from WebRTC project

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libabsl_strings.so:devel/abseil

USES=		compiler:c++14-lang meson
USE_LDCONFIG=	yes
CFLAGS_armv6=	-DPFFFT_SIMD_DISABLE # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/issues/6
CFLAGS_i386=	-msse # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/issues/5

.include <bsd.port.mk>
