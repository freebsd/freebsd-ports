PORTNAME=	taxonkit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Practical and efficient NCBI taxonomy toolkit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/shenwei356/taxonkit
GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
