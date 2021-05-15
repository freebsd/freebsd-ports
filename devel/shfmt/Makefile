PORTNAME=	shfmt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.4
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Shell script formatter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	mvdan.cc/sh/v3
GO_TARGET=	./cmd/shfmt
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/shfmt

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	man/man1/shfmt.1.gz

do-install-MANPAGES-on:
	scdoc < ${WRKSRC}/cmd/shfmt/shfmt.1.scd \
		> ${STAGEDIR}${MAN1PREFIX}/man/man1/shfmt.1

.include <bsd.port.mk>
