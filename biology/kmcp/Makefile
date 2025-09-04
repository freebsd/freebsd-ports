PORTNAME=	kmcp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4
PORTREVISION=	15
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Accurate metagenomic profiling & fast large-scale genome searching
WWW=		https://bioinf.shenwei.me/kmcp/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/shenwei356/kmcp
GO_TARGET=	./kmcp

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
