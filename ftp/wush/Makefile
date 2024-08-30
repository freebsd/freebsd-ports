PORTNAME=	wush
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	ftp

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Command-line file transfer tool over wireguard
WWW=		https://github.com/coder/wush

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

GO_MODULE=	github.com/coder/wush
GO_TARGET=	./cmd/wush
PLIST_FILES=	bin/wush

.include <bsd.port.mk>
