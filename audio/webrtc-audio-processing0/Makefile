# $FreeBSD$

PORTNAME=	webrtc-audio-processing
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://freedesktop.org/software/pulseaudio/${PORTNAME}/
PKGNAMESUFFIX=	0

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	AudioProcessing module from WebRTC project (legacy version)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib libtool pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
