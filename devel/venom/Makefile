PORTNAME=	venom
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	12
CATEGORIES=	devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Manage and run integration tests with efficiency
WWW=		https://github.com/ovh/venom

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/ovh/venom
GO_TARGET=	./cmd/venom
GO_BUILDFLAGS=	-ldflags "-X github.com/ovh/venom.Version=v${PORTVERSION}"

PLIST_FILES=	bin/venom

.include <bsd.port.mk>
