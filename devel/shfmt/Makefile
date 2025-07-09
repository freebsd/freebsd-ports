PORTNAME=	shfmt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.12.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Shell script formatter
WWW=		https://github.com/mvdan/sh

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc

USES=		go:modules
GO_MODULE=	mvdan.cc/sh/v3
GO_TARGET=	./cmd/shfmt
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/shfmt \
		share/man/man1/shfmt.1.gz

post-install:
	scdoc < ${WRKSRC}/cmd/shfmt/shfmt.1.scd \
		> ${STAGEDIR}${PREFIX}/share/man/man1/shfmt.1

.include <bsd.port.mk>
