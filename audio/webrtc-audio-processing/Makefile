# $FreeBSD$

PORTNAME=	webrtc-audio-processing
DISTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	https://freedesktop.org/software/pulseaudio/${PORTNAME}/

PATCH_SITES=	https://gitlab.freedesktop.org/pulseaudio/${PORTNAME}/-/commit/
PATCHFILES+=	2083c9a5dd34.diff:-p1 # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/merge_requests/6

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	AudioProcessing module from WebRTC project

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libabsl_strings.so:devel/abseil

USES=		compiler:c++14-lang localbase:ldflags meson
USE_LDCONFIG=	yes
CFLAGS_i386=	-msse # https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/issues/5

post-patch:
# https://gitlab.freedesktop.org/pulseaudio/webrtc-audio-processing/-/issues/4
	@${REINPLACE_CMD} '/absl/s/registry/reflection/' ${WRKSRC}/meson.build

.include <bsd.port.mk>
