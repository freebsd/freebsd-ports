# $FreeBSD$

PORTNAME=	webrtc-audio-processing
DISTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://freedesktop.org/software/pulseaudio/${PORTNAME}/

PATCH_SITES=	https://gitlab.freedesktop.org/pulseaudio/${PORTNAME}/-/commit/
PATCHFILES+=	2083c9a5dd34.diff:-p1 # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/merge_requests/6
PATCHFILES+=	3f9907f93d39.diff:-p1 # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/merge_requests/13
PATCHFILES+=	b34c1d5746ea.diff:-p1 # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/merge_requests/14

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	AudioProcessing module from WebRTC project

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc=		fails to compile: ./webrtc/rtc_base/system/arch.h:54:2: Please add support for your architecture in rtc_base/system/arch.h
BROKEN_powerpc64=	fails to compile: ./webrtc/rtc_base/system/arch.h:54:2: Please add support for your architecture in rtc_base/system/arch.h
BROKEN_riscv64=		fails to compile: ./webrtc/rtc_base/system/arch.h:54:2: Please add support for your architecture in rtc_base/system/arch.h

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libabsl_strings.so:devel/abseil

USES=		compiler:c++17-lang meson
USE_LDCONFIG=	yes
CFLAGS_i386=	-msse # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/issues/5

.include <bsd.port.mk>
