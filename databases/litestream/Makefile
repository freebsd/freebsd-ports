PORTNAME=	litestream
PORTVERSION=	0.5.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Streaming replication for SQLite
WWW=		https://litestream.io/ \
		https://github.com/benbjohnson/litestream

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/benbjohnson/litestream
GO_TARGET=	./cmd/litestream

PLIST_FILES=	bin/litestream

.include <bsd.port.mk>
