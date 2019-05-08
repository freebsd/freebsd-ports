# $FreeBSD$

PORTNAME=	ghq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.1
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Remote repository management made easy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_PKGNAME=	github.com/motemen/ghq
USE_GITHUB=	yes
GH_ACCOUNT=	motemen
GH_TUPLE=	blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		daviddengcn:go-colortext:186a3d44e920:daviddengcn_go_colortext/vendor/github.com/daviddengcn/go-colortext \
		golang:net:f4e77d36d62c:golang_net/vendor/golang.org/x/net \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:xerrors:385005612d73:golang_xerrors/vendor/golang.org/x/xerrors \
		motemen:go-colorine:45d19169413a:motemen_go_colorine/vendor/github.com/motemen/go-colorine \
		urfave:cli:v1.20.0:urfave_cli/vendor/github.com/urfave/cli

PLIST_FILES=	bin/ghq \
		share/zsh/site-functions/_ghq

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
MANPAGES_PLIST_FILES=	man/man1/ghq.1.gz

post-build-MANPAGES-on:
	cd ${WRKSRC} && asciidoctor -b manpage -d manpage ghq.txt

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/zsh/_ghq \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/ghq.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
