# $FreeBSD$

PORTNAME=	gh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.5
CATEGORIES=	devel

MAINTAINER=	vulcan@wired.sh
COMMENT=	GitHub command-line tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	cli
GH_PROJECT=	cli
GH_TUPLE=	AlecAivazis:survey:v2.0.4:alecaivazis_survey/vendor/github.com/AlecAivazis/survey/v2 \
		alecthomas:chroma:v0.6.8:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		aybabtme:rgbterm:cc83f3b3ce59:aybabtme_rgbterm/vendor/github.com/aybabtme/rgbterm \
		cpuguy83:go-md2man:v1.0.10:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		dlclark:regexp2:v1.1.6:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		go-yaml:yaml:fc94e3f71652:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml_1/vendor/gopkg.in/yaml.v2 \
		golang:crypto:20be4c3c3ed5:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:fde4db37ae7a:golang_sys/vendor/golang.org/x/sys \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		mattn:go-colorable:v0.1.2:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.9:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		russross:blackfriday:v2.0.1:russross_blackfriday_1/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		tj:go-css:220a796d1705:tj_go_css/vendor/github.com/tj/go-css \
		vilmibm:go-termd:v0.0.4:vilmibm_go_termd/vendor/github.com/vilmibm/go-termd

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/command.Version=${BUILD_VERSION} \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/command.BuildDate=${BUILD_DATE}"

BUILD_VERSION=	${DISTVERSION}
BUILD_DATE=	$$(date +%Y-%m-%d)

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME}.bash \
		share/fish/completions/${PORTNAME}.fish \
		share/zsh/site_functions/_${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-build:
.for shell in bash fish zsh 
	${WRKDIR}/bin/${PORTNAME} completion -s ${shell} > ${WRKSRC}/${shell}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site_functions
	${INSTALL_DATA} ${WRKSRC}/zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site_functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${GO_WRKSRC} && ${SETENV} ${GO_ENV} ${GO_CMD} test ./...

.include <bsd.port.mk>
