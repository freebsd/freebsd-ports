PORTNAME=	piper
DISTVERSION=	2023.11.14
PORTREVISION=	1
DISTVERSIONSUFFIX=	-2
CATEGORIES=	audio

MAINTAINER=	kenrap@kennethraplee.com
COMMENT=	Fast, local text to speech system
WWW=		https://rhasspy.github.io/piper-samples/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libespeak-ng.so:audio/espeak-ng \
		libfmt.so:devel/libfmt \
		libonnxruntime.so:misc/onnxruntime \
		libpiper_phonemize.so:audio/piper-phonemize \
		libspdlog.so:devel/spdlog

USES=		compiler:c++17-lang cmake localbase pkgconfig tar:xz xorg
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	rhasspy

PLIST_FILES=	bin/piper

.include <bsd.port.mk>
