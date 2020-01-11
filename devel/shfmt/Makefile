# $FreeBSD$

PORTNAME=	shfmt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
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
		golang:crypto:34f69633bfdc:golang_crypto/vendor/golang.org/x/crypto \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		golang:xerrors:1b5146add898:golang_xerrors/vendor/golang.org/x/xerrors \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		mvdan:editorconfig:890940e3f00e:mvdan_editorconfig/vendor/mvdan.cc/editorconfig \
		pkg:diff:531926345625:pkg_diff/vendor/github.com/pkg/diff \
		rogpeppe:go-internal:v1.5.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal
GO_TARGET=	./cmd/shfmt
PLIST_FILES=	bin/shfmt

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} \
		./cmd/shfmt

.include <bsd.port.mk>
