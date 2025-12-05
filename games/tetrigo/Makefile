PORTNAME=	tetrigo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	5
CATEGORIES=	games

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tetris in terminal
WWW=		https://github.com/Broderick-Westrope/tetrigo

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:1.23,modules

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

GO_MODULE=	github.com/Broderick-Westrope/tetrigo
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
