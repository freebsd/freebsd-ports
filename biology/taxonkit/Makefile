PORTNAME=	taxonkit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.0
PORTREVISION=	4
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Practical and efficient NCBI taxonomy toolkit
WWW=		https://bioinf.shenwei.me/taxonkit/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/shenwei356/taxonkit
GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
