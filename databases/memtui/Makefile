PORTNAME=	memtui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.6
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Modern TUI client for Memcached with Vim keybindings
WWW=		https://github.com/nnnkkk7/memtui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/nnnkkk7/memtui
GO_TARGET=	./cmd/memtui

PLIST_FILES=	bin/memtui

.include <bsd.port.mk>
