PORTNAME=	venom
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Manage and run integration tests with efficiency
WWW=		https://github.com/ovh/venom

LICENSE=	APACHE20
LICENSE_FILES=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/ovh/venom
GO_TARGET=	./cmd/venom

PLIST_FILES=	bin/venom

.include <bsd.port.mk>
