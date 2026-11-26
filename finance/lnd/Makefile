PORTNAME=	lnd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.3-beta
PORTREVISION=	32
CATEGORIES=	finance

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightning Network Daemon
WWW=		https://github.com/lightningnetwork/lnd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules

CPE_VENDOR=	lightning_network_daemon_project
CPE_PRODUCT=	lightning_network_daemon
CPE_VERSION=	${DISTVERSION:C/-.*//}
CPE_UPDATE=	${DISTVERSION:C/^[^-]*-//:S/-/_/g}

GO_MODULE=	github.com/lightningnetwork/lnd
GO_TARGET=	./cmd/lnd \
		./cmd/lncli

PLIST_FILES=	bin/${PORTNAME} \
		bin/lncli

.include <bsd.port.mk>
