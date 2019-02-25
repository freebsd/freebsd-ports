# $FreeBSD$

PORTNAME=		git-lfs
DISTVERSIONPREFIX=	v
DISTVERSION=		2.7.0
CATEGORIES=		devel

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Git extension for versioning large files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	git:devel/git

USES=		go
USE_GITHUB=	yes

GH_TUPLE=	alexbrainman:sspi:4729b3d:abm_sspi/vendor/github.com/alexbrainman/sspi \
	git-lfs:gitobj:v1.1.0:glfs_obj/vendor/github.com/git-lfs/gitobj \
	git-lfs:go-netrc:e0e9ca4:glfs_netrc/vendor/github.com/git-lfs/go-netrc \
	git-lfs:wildmatch:v1.0.2:glfs_wildm/vendor/github.com/git-lfs/wildmatch \
	inconshreveable:mousetrap:v1.0.0:ir_mtrap/vendor/github.com/inconshreveable/mousetrap \
	kr:pty:5cf931e:kr_pty/vendor/github.com/kr/pty \
	mattn:go-isatty:v0.0.4:mattn_isatty/vendor/github.com/mattn/go-isatty \
	olekukonko:ts:78ecb04:okk_ts/vendor/github.com/olekukonko/ts \
	pkg:errors:c605e28:pkg_err/vendor/github.com/pkg/errors \
	rubyist:tracerx:7879593:rubyist_tracerx/vendor/github.com/rubyist/tracerx \
	spf13:cobra:v0.0.3:spf_cobra/vendor/github.com/spf13/cobra \
	spf13:pflag:v1.0.3:spf_pflag/vendor/github.com/spf13/pflag \
	stretchr:testify:v1.2.2:stretch_testify/vendor/github.com/stretchr/testify \
	ThomsonReutersEikon:go-ntlm:b00ec39:tre_ntlm/vendor/github.com/ThomsonReutersEikon/go-ntlm \
	xeipuuv:gojsonpointer:4e3ac27:xei_pointer/vendor/github.com/xeipuuv/gojsonpointer \
	xeipuuv:gojsonreference:bd5ef7b:xei_ref/vendor/github.com/xeipuuv/gojsonreference \
	xeipuuv:gojsonschema:6b67b3f:xei_schem/vendor/github.com/xeipuuv/gojsonschema \
	golang:sync:37e7f08:golang_sync/vendor/golang.org/x/sync \
	golang:sys:fa5fdf9:golang_sys/vendor/golang.org/x/sys

GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	ronn:textproc/rubygem-ronn

pre-build:
	${RM} ${GO_WRKSRC}/go.mod

post-build-MANPAGES-on:
	cd ${GO_WRKSRC}/docs/man && ${LOCALBASE}/bin/ronn -r *.ronn

post-install-MANPAGES-on:
	${INSTALL_MAN} ${GO_WRKSRC}/docs/man/*.1 ${STAGEDIR}${LOCALBASE}/man/man1
	${INSTALL_MAN} ${GO_WRKSRC}/docs/man/*.5 ${STAGEDIR}${LOCALBASE}/man/man5

.include <bsd.port.mk>
