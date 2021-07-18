PORTNAME=	unikmer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.1
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Toolkit for nucleic acid k-mer analysis, set operations on k-mers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/shenwei356/unikmer
GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
