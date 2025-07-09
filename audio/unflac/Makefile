PORTNAME=	unflac
DISTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	audio

MAINTAINER=	bsd@abinet.ru
COMMENT=	Console tool for frame accurate audio image + cue sheet splitting
WWW=		https://git.sr.ht/~ft/unflac

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		go:modules
GO_MODULE=	git.sr.ht/~ft/unflac@v0.0.0-20240408174655-b5026a6dfc5a

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
