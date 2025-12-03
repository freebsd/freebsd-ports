PORTNAME=	litestream
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone streaming replication tool for SQLite
WWW=		https://litestream.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

#BROKEN_i386=	build error: constant 9223372036854775807 overflows int.

USES=		go:modules

GO_MODULE=	github.com/benbjohnson/litestream
GO_TARGET= 	github.com/benbjohnson/litestream/cmd/litestream

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
