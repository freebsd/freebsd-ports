# $FreeBSD$

PORTNAME=	shfmt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.4
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Shell script formatter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	mvdan
GH_PROJECT=	sh
GH_TUPLE=	golang:sys:201ba4db2418:golang_sys/vendor/golang.org/x/sys \
		golang:term:ad39bd3f0407:golang_term/vendor/golang.org/x/term \
		google:renameio:v0.1.0:google_renameio/vendor/github.com/google/renameio \
		mvdan:editorconfig:e40951bde157:mvdan_editorconfig/vendor/mvdan.cc/editorconfig \
		pkg:diff:5b29258ca4f7:pkg_diff/vendor/github.com/pkg/diff \
		rogpeppe:go-internal:v1.6.2:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal

GO_TARGET=	./cmd/shfmt
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${DISTVERSIONFULL}"
GO_TESTTARGET=	./cmd/shfmt

PLIST_FILES=	bin/shfmt

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	man/man1/shfmt.1.gz

do-install-MANPAGES-on:
	scdoc < ${WRKSRC}/cmd/shfmt/shfmt.1.scd \
		> ${STAGEDIR}${MAN1PREFIX}/man/man1/shfmt.1

.include <bsd.port.mk>
