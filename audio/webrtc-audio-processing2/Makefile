PORTNAME=	webrtc-audio-processing
DISTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://freedesktop.org/software/pulseaudio/${PORTNAME}/
PKGNAMESUFFIX=	2

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	AudioProcessing module from WebRTC project (newer API)
WWW=		https://freedesktop.org/software/pulseaudio/webrtc-audio-processing/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libabsl_strings.so:devel/abseil

USES=		compiler:c++17-lang meson pkgconfig
USE_LDCONFIG=	yes
MESON_DISABLED=	${ARCH:Narmv?:Naarch64:C/.+/neon/}
MESON_FALSE=	${ARCH:Mi386:C/.+/inline-sse/}

.include <bsd.port.mk>
