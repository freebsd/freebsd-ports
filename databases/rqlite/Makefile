PORTNAME=	rqlite
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.2
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight, distributed relational database built on SQLite
WWW=		https://rqlite.io \
		https://github.com/rqlite/rqlite

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules

GO_MODULE=	github.com/rqlite/rqlite/v9
GO_TARGET=	./cmd/rqbench \
		./cmd/rqlite \
		./cmd/rqlited

PLIST_FILES=	bin/rqbench \
		bin/rqlite \
		bin/rqlited

.include <bsd.port.mk>
