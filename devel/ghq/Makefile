# $FreeBSD$

PORTNAME=	ghq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.3
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Repository management tool (Git, Hg, SVN, Fossil, Bazaar, Darcs)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	git>0:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	motemen
GH_TUPLE=	Songmu:gitconfig:v0.0.2:songmu_gitconfig/vendor/github.com/Songmu/gitconfig \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man/v2 \
		daviddengcn:go-colortext:186a3d44e920:daviddengcn_go_colortext/vendor/github.com/daviddengcn/go-colortext \
		go-yaml:yaml:v2.2.7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:net:c0dbc17a3553:golang_net/vendor/golang.org/x/net \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		motemen:go-colorine:45d19169413a:motemen_go_colorine/vendor/github.com/motemen/go-colorine \
		russross:blackfriday:v2.0.1:russross_blackfriday/vendor/github.com/russross/blackfriday/v2 \
		saracen:walker:324a081bae7e:saracen_walker/vendor/github.com/saracen/walker \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		urfave:cli:v2.1.0:urfave_cli/vendor/github.com/urfave/cli/v2

PLIST_FILES=	bin/ghq \
		etc/bash-completion.d/_ghq \
		share/zsh/site-functions/_ghq

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
MANPAGES_PLIST_FILES=	man/man1/ghq.1.gz

post-build-MANPAGES-on:
	cd ${WRKSRC} && asciidoctor -b manpage -d manpage -o ghq.1 README.adoc

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash-completion.d
	${INSTALL_DATA} ${WRKSRC}/misc/bash/_ghq \
		${STAGEDIR}${PREFIX}/etc/bash-completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/_ghq \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/ghq.1 ${STAGEDIR}${PREFIX}/man/man1

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} \
		./

.include <bsd.port.mk>
