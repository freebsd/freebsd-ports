# $FreeBSD$

PORTNAME=	ghq
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.5
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Repository management tool (Git, Hg, SVN, Fossil, Bazaar, Darcs)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	git>0:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	x-motemen
GH_TUPLE=	\
		Songmu:gitconfig:v0.1.0:songmu_gitconfig/vendor/github.com/Songmu/gitconfig \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		daviddengcn:go-colortext:v1.0.0:daviddengcn_go_colortext/vendor/github.com/daviddengcn/go-colortext \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		goccy:go-yaml:v1.8.0:goccy_go_yaml/vendor/github.com/goccy/go-yaml \
		golang:net:ab3426394381:golang_net/vendor/golang.org/x/net \
		golang:sync:6e8e738ad208:golang_sync/vendor/golang.org/x/sync \
		golang:sys:76b94024e4b6:golang_sys/vendor/golang.org/x/sys \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		mattn:go-colorable:v0.1.7:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		motemen:go-colorine:45d19169413a:motemen_go_colorine/vendor/github.com/motemen/go-colorine \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		saracen:walker:v0.1.1:saracen_walker/vendor/github.com/saracen/walker \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		urfave:cli:v2.2.0:urfave_cli_v2/vendor/github.com/urfave/cli/v2

PLIST_FILES=	bin/ghq \
		etc/bash_completion.d/_ghq \
		share/zsh/site-functions/_ghq

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
MANPAGES_PLIST_FILES=	share/man/man1/ghq.1.gz

post-build-MANPAGES-on:
	cd ${WRKSRC} && asciidoctor -b manpage -d manpage -o ghq.1 README.adoc

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/misc/bash/_ghq \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/_ghq \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/ghq.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
