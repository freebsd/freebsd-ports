PORTNAME=	cointop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.10
PORTREVISION=	15
CATEGORIES=	finance

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Cryptocurrency coin stats
WWW=		https://github.com/miguelmota/cointop

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Repo archived upstream Nov 18, 2023
EXPIRATION_DATE=2024-02-29

USES=		go:modules
GO_MODULE=	github.com/${PORTNAME}-sh/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X ${GO_MODULE}/cointop.version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
