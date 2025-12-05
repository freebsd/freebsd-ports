PORTNAME=	wallhaven-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.5
PORTREVISION=	7
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CLI for wallhaven to browse wallpapers in terminal
WWW=		https://github.com/r3tr0ananas/wallhaven-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	chafa:graphics/chafa \
		fzf:textproc/fzf

USES=		go:1.23,modules

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

GO_MODULE=	github.com/r3tr0ananas/wallhaven-cli/v2
GO_TARGET=	./wallhaven
PLIST_FILES=	bin/wallhaven

.include <bsd.port.mk>
