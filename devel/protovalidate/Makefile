PORTNAME=	protovalidate
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Protocol Buffer Validation
WWW=		https://protovalidate.com/ \
		https://github.com/bufbuild/protovalidate

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/bufbuild/protovalidate/tools
GO_TARGET=	./protovalidate-conformance \
		./protovalidate-migrate

PLIST_FILES=	bin/protovalidate-conformance \
		bin/protovalidate-migrate

.include <bsd.port.mk>
