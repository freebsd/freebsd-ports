PORTNAME=	sonicradio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.11
CATEGORIES=	audio

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	TUI radio player making use of Radio Browser API
WWW=		https://github.com/dancnb/sonicradio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		go:1.23,modules pkgconfig
GO_MODULE=	github.com/dancnb/sonicradio

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

PLIST_FILES=	bin/sonicradio

.include <bsd.port.mk>
