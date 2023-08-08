PORTNAME=	webrtc-audio-processing
DISTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	https://freedesktop.org/software/pulseaudio/${PORTNAME}/

PATCH_SITES=	https://gitlab.freedesktop.org/pulseaudio/${PORTNAME}/-/commit/
PATCHFILES+=	2083c9a5dd34.patch:-p1 # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/merge_requests/6
PATCHFILES+=	d49a0855a33b.patch:-p1 # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/merge_requests/17
PATCHFILES+=	f29ff57d6ccd.patch:-p1 # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/merge_requests/17
PATCHFILES+=	c18b3945a1cc.patch:-p1 # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/merge_requests/17

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	AudioProcessing module from WebRTC project
WWW=		https://freedesktop.org/software/pulseaudio/webrtc-audio-processing/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc=		fails to compile: ./webrtc/rtc_base/system/arch.h:54:2: Please add support for your architecture in rtc_base/system/arch.h
BROKEN_riscv64=		fails to compile: ./webrtc/rtc_base/system/arch.h:54:2: Please add support for your architecture in rtc_base/system/arch.h

BUILD_DEPENDS=	abseil>0:devel/abseil

USES=		compiler:c++17-lang meson pkgconfig
USE_LDCONFIG=	yes
CFLAGS_i386=	-msse # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/issues/5

.include <bsd.port.mk>
