PORTNAME=	air
DISTVERSIONPREFIX=	v
DISTVERSION=	1.62.0
PORTREVISION=	4
CATEGORIES=	devel
PKGNAMESUFFIX=	-go

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Live reload for Go apps
WWW=		https://github.com/air-verse/air

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/air-verse/air

CONFLICTS_INSTALL=	air

PLIST_FILES=	bin/air

.include <bsd.port.mk>
