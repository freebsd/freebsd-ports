PORTNAME=	songsee
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio visualizer: spectrograms, mel, chroma, and more
WWW=		https://github.com/steipete/songsee

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		go:1.25+,modules

GO_MODULE=	github.com/steipete/songsee

GO_TARGET=	./cmd/songsee

PLIST_FILES=	bin/songsee

.include <bsd.port.mk>
