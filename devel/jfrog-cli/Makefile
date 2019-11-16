# $FreeBSD$

PORTNAME=	jfrog-cli
PORTVERSION=	1.25.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI client for Artifactory

BROKEN=		unfetchable

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_TUPLE=	jfrog:jfrog-cli-go:${PORTVERSION}:DEFAULT \
		buger:jsonparser:6acdf74:buger_jsonparser/vendor/github.com/buger/jsonparser \
		chzyer:readline:2972be2:chzyer_readline/vendor/github.com/chzyer/readline \
		codegangsta:cli:v1.20.0:codegangsta_cli/vendor/github.com/codegangsta/cli \
		dsnet:compress:cc9eb1d:dsnet_compress/vendor/github.com/dsnet/compress \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-warnings:warnings:v0.1.2:warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:505ab14:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:adae6a3:golang_net/vendor/golang.org/x/net \
		golang:snappy:2e65f85:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:5ac8a44:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		jbenet:go-context:d14ea06:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jfrog:gocmd:v0.1.8:jfrog_gocmd/vendor/github.com/jfrog/gocmd \
		jfrog:gofrog:v1.0.4:jfrog_gofrog/vendor/github.com/jfrog/gofrog \
		jfrog:jfrog-client-go:v0.3.3:jfrog_jfrog_client_go/vendor/github.com/jfrog/jfrog-client-go \
		kevinburke:ssh_config:81db2a7:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		magiconair:properties:v1.8.0:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-shellwords:v1.0.3:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		mholt:archiver:v2.1.0:mholt_archiver/vendor/github.com/mholt/archiver \
		mitchellh:go-homedir:v1.0.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.0.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		nwaples:rardecode:e06696f:nwaples_rardecode/vendor/github.com/nwaples/rardecode \
		pelletier:go-buffruneio:v0.2.0:pelletier_go_buffruneio/vendor/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pierrec:lz4:v2.0.5:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.2.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.2:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.2.1:spf13_viper/vendor/github.com/spf13/viper \
		src-d:gcfg:v1.3.0:src_d_gcfg/vendor/github.com/src-d/gcfg \
		src-d:go-billy:v4.3.0:gobilly/vendor/gopkg.in/src-d/go-billy.v4 \
		src-d:go-git:v4.7.0:gogit/vendor/gopkg.in/src-d/go-git.v4 \
		ulikunitz:xz:v0.5.4:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xanzy:ssh-agent:v0.2.0:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent

GO_TARGET=	./jfrog-cli/jfrog
PLIST_FILES=	bin/jfrog

.include <bsd.port.mk>
