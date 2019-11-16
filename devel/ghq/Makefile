# $FreeBSD$

PORTNAME=	ghq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.8
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Remote repository management made easy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	motemen
GH_TUPLE=	Songmu:gitconfig:v0.0.2:songmu_gitconfig/vendor/github.com/Songmu/gitconfig \
		daviddengcn:go-colortext:186a3d44e920:daviddengcn_go_colortext/vendor/github.com/daviddengcn/go-colortext \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:net:3b0461eec859:golang_net/vendor/golang.org/x/net \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:f43be2a4598c:golang_sys/vendor/golang.org/x/sys \
		golang:xerrors:a985d3407aa7:golang_xerrors/vendor/golang.org/x/xerrors \
		motemen:go-colorine:45d19169413a:motemen_go_colorine/vendor/github.com/motemen/go-colorine \
		saracen:walker:c86836c89b0d:saracen_walker/vendor/github.com/saracen/walker \
		urfave:cli:v1.20.0:urfave_cli/vendor/github.com/urfave/cli

PLIST_FILES=	bin/ghq \
		share/zsh/site-functions/_ghq

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
MANPAGES_PLIST_FILES=	man/man1/ghq.1.gz

post-build-MANPAGES-on:
	cd ${WRKSRC} && asciidoctor -b manpage -d manpage -o ghq.1 README.adoc

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/zsh/_ghq \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/ghq.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
