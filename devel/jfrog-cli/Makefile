# $FreeBSD$

PORTNAME=	jfrog-cli
PORTVERSION=	1.22.1
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI client for Artifactory

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_TUPLE=	jfrog:jfrog-cli-go:3f06184:DEFAULT/src/github.com/jfrog/jfrog-cli-go \
		jfrog:jfrog-client-go:v0.1.3:client/src/github.com/jfrog/jfrog-client-go \
		codegangsta:cli:v1.20.0:cli/src/github.com/codegangsta/cli \
		buger:jsonparser:6acdf747ae99:jsonparser/src/github.com/buger/jsonparser \
		chzyer:readline:2972be24d48e:readline/src/github.com/chzyer/readline \
		jfrog:gofrog:v1.0.2:gofrog/src/github.com/jfrog/gofrog \
		mholt:archiver:v2.1.0:archiver/src/github.com/mholt/archiver \
		dsnet:compress:cc9eb1d:compress/src/github.com/dsnet/compress \
		golang:snappy:2e65f85255db:snappy/src/github.com/golang/snappy \
		mattn:go-shellwords:v1.0.3:shellwords/src/github.com/mattn/go-shellwords \
		nwaples:rardecode:e06696f847ae:rardecode/src/github.com/nwaples/rardecode \
		pierrec:lz4:v2.0.5:lz4/src/github.com/pierrec/lz4 \
		spf13:viper:v1.2.1:viper/src/github.com/spf13/viper \
		fsnotify:fsnotify:v1.4.7:fsnotify/src/github.com/fsnotify/fsnotify \
		hashicorp:hcl:v1.0.0:hcl/src/github.com/hashicorp/hcl \
		magiconair:properties:v1.8.0:properties/src/github.com/magiconair/properties \
		mitchellh:mapstructure:v1.0.0:mapstructure/src/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.2.0:pelletier/src/github.com/pelletier/go-toml \
		spf13:afero:v1.1.2:afera/src/github.com/spf13/afero \
		spf13:cast:v1.2.0:cast/src/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:jwalterweatherman/src/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.2:pflag/src/github.com/spf13/pflag \
		ulikunitz:xz:v0.5.4:xz/src/github.com/ulikunitz/xz \
		xanzy:ssh-agent:v0.2.0:sshagent/src/github.com/xanzy/ssh-agent \
		golang:crypto:e363607:crypto/src/golang.org/x/crypto \
		golang:sys:8cf3aee42992:sys/src/golang.org/x/sys \
		golang:text:v0.3.0:text/src/golang.org/x/text \
		src-d:go-git:v4.7.0:gogit/src/gopkg.in/src-d/go-git.v4 \
		emirpasic:gods:v1.12.0:gods/src/github.com/emirpasic/gods \
		jbenet:go-context:d14ea06fba99:context/src/github.com/jbenet/go-context \
		kevinburke:ssh_config:81db2a75821e:sshconfig/src/github.com/kevinburke/ssh_config \
		mitchellh:go-homedir:v1.0.0:homedir/src/github.com/mitchellh/go-homedir \
		pelletier:go-buffruneio:v0.2.0:buffruneio/src/github.com/pelletier/go-buffruneio \
		sergi:go-diff:v1.0.0:godiff/src/github.com/sergi/go-diff \
		src-d:gcfg:v1.3.0:gcfg/src/github.com/src-d/gcfg \
		golang:net:4dfa2610cdf3:net/src/golang.org/x/net \
		src-d:go-billy:v4.3.0:gobilly/src/gopkg.in/src-d/go-billy.v4 \
		go-yaml:yaml:v2.2.1:yaml/src/gopkg.in/yaml.v2 \
		go-warnings:warnings:v0.1.2:warnings/src/gopkg.in/warnings.v0

PLIST_FILES=	bin/jfrog

do-build:
	@cd ${WRKSRC}/src/github.com/jfrog/jfrog-cli-go/jfrog-cli/jfrog ; \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/jfrog ${STAGEDIR}${PREFIX}/bin/jfrog

.include <bsd.port.mk>
