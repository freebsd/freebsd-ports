PORTNAME=	sonicradio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.4
CATEGORIES=	audio

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	TUI radio player making use of Radio Browser API
WWW=		https://github.com/dancnb/sonicradio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		go:1.23,modules pkgconfig
GO_MODULE=	github.com/dancnb/sonicradio

PLIST_FILES=	bin/sonicradio

.include <bsd.port.mk>
