PORTNAME=	lazyworktree
DISTVERSIONPREFIX=	v
DISTVERSION=	1.49.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI for managing Git worktrees
WWW=		https://github.com/chmouel/lazyworktree

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/chmouel/lazyworktree
GO_TARGET=	./cmd/lazyworktree
GO_LDFLAGS=	-X main.version=${DISTVERSION}

PLIST_FILES=	bin/lazyworktree

.include <bsd.port.mk>
