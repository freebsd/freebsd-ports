PORTNAME=	pget
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	14
CATEGORIES=	ftp net www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, resumable file download client
WWW=		https://github.com/Code-Hex/pget

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/Code-Hex/pget
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
