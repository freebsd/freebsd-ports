PORTNAME=	seqkit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform and ultrafast toolkit for FASTA/Q file manipulation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/shenwei356/seqkit
GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
