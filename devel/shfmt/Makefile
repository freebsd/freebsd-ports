# $FreeBSD$

PORTNAME=	shfmt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Format shell scripts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	mvdan
GH_PROJECT=	sh
GH_TUPLE=	go-errgo:errgo:v2.1.0:go_errgo_errgo/vendor/gopkg.in/errgo.v2 \
		golang:sys:9197077df867:golang_sys/vendor/golang.org/x/sys \
		golang:term:ad39bd3f0407:golang_term/vendor/golang.org/x/term \
		google:renameio:v0.1.0:google_renameio/vendor/github.com/google/renameio \
		mvdan:editorconfig:e40951bde157:mvdan_editorconfig/vendor/mvdan.cc/editorconfig \
		pkg:diff:531926345625:pkg_diff/vendor/github.com/pkg/diff \
		rogpeppe:go-internal:v1.5.2:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal
GO_TARGET=	./cmd/shfmt
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${DISTVERSIONFULL}"
GO_TESTTARGET=	./cmd/shfmt
PLIST_FILES=	bin/shfmt

.include <bsd.port.mk>
