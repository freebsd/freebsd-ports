PORTNAME=	taskctl
PORTVERSION=	1.4.2
PORTREVISION=	30
CATEGORIES=	devel

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Simple modern alternative to GNU Make
WWW=		https://github.com/taskctl/taskctl

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

USE_GITHUB=	yes
GO_TARGET=	./cmd/taskctl
GH_TUPLE=	bmatcuk:doublestar:v1.1.5:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		briandowns:spinner:6dc224009eae:briandowns_spinner/vendor/github.com/briandowns/spinner \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		cpuguy83:go-md2man:f79a8a8ca69d:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		emicklei:dot:v0.10.2:emicklei_dot/vendor/github.com/emicklei/dot \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:ad39bd3f0407:golang_term/vendor/golang.org/x/term \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		logrusorgru:aurora:dc85c304c434:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		lunixbochs:vtclean:2d01aacdc34a:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		manifoldco:promptui:v0.7.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.10:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mvdan:sh:v3.1.1:mvdan_sh/vendor/mvdan.cc/sh/v3 \
		pelletier:go-toml:v1.8.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		urfave:cli:v2.2.0:urfave_cli_v2/vendor/github.com/urfave/cli/v2

PLIST_FILES=	bin/taskctl

.include <bsd.port.mk>
