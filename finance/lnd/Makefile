PORTNAME=	lnd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.3-beta
PORTREVISION=	13
CATEGORIES=	finance

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightning Network Daemon
WWW=		https://github.com/lightningnetwork/lnd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/lightningnetwork/lnd
GO_TARGET=	./cmd/lnd \
		./cmd/lncli

PLIST_FILES=	bin/${PORTNAME} \
		bin/lncli

.include <bsd.port.mk>
