PORTNAME=	sag
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mac-style speech synthesis using ElevenLabs
WWW=		https://github.com/steipete/sag

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24+,modules pkgconfig

LIB_DEPENDS=	libasound.so:audio/alsa-lib

GO_MODULE=	github.com/steipete/sag
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
