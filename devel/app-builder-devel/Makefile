PORTNAME=	app-builder
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.0-alpha.13
PORTREVISION=	5
CATEGORIES=	devel
PKGNAMESUFFIX=	-devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Generic helper tool to build app in a distributable format (development version)
WWW=		https://github.com/develar/app-builder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go-bindata:devel/go-bindata
RUN_DEPENDS=	opj_decompress:graphics/openjpeg

USES=		gmake go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	develar
GH_TUPLE=	\
		aclements:go-rabin:d0b643ea1a4c:aclements_go_rabin/vendor/github.com/aclements/go-rabin \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/github.com/alecthomas/kingpin \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:b94a6e3cc137:alecthomas_units/vendor/github.com/alecthomas/units \
		alessio:shellescape:52074bc9df61:alessio_shellescape_1/vendor/gopkg.in/alessio/shellescape.v1 \
		alessio:shellescape:b115ca0f9053:alessio_shellescape/vendor/github.com/alessio/shellescape \
		aws:aws-sdk-go:v1.45.7:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		biessek:golang-ico:d348d9ea4670:biessek_golang_ico/vendor/github.com/biessek/golang-ico \
		bmizerany:assert:b7ed37b82869:bmizerany_assert/vendor/github.com/bmizerany/assert \
		develar:errors:v0.9.0:develar_errors/vendor/github.com/develar/errors \
		develar:go-fs-util:69a2d4542206:develar_go_fs_util/vendor/github.com/develar/go-fs-util \
		develar:go-pkcs12:54baa4f32c6a:develar_go_pkcs12/vendor/github.com/develar/go-pkcs12 \
		disintegration:imaging:v1.6.2:disintegration_imaging/vendor/github.com/disintegration/imaging \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:exp:bbda1eaf7a17:golang_exp/vendor/golang.org/x/exp \
		golang:image:v0.12.0:golang_image/vendor/golang.org/x/image \
		golang:net:v0.6.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.12.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.13.0:golang_text/vendor/golang.org/x/text \
		hpcloud:tail:v1.0.0:hpcloud_tail/vendor/github.com/hpcloud/tail \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		jsummers:gobmp:a9de23ed2e25:jsummers_gobmp/vendor/github.com/jsummers/gobmp \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.19:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mcuadros:go-version:035f6764e8d2:mcuadros_go_version/vendor/github.com/mcuadros/go-version \
		minio:blake2b-simd:3f5f724cb5b1:minio_blake2b_simd/vendor/github.com/minio/blake2b-simd \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		onsi:ginkgo:v1.8.0:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.5.0:onsi_gomega/vendor/github.com/onsi/gomega \
		oxtoacart:bpool:03653db5a59c:oxtoacart_bpool/vendor/github.com/oxtoacart/bpool \
		phayes:permbits:39d7c581d2ee:phayes_permbits/vendor/github.com/phayes/permbits \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:xattr:v0.4.9:pkg_xattr/vendor/github.com/pkg/xattr \
		samber:lo:v1.38.1:samber_lo/vendor/github.com/samber/lo \
		segmentio:ksuid:v1.0.4:segmentio_ksuid/vendor/github.com/segmentio/ksuid \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.25.0:uber_go_zap/vendor/go.uber.org/zap \
		zieckey:goini:0da17d361d26:zieckey_goini/vendor/github.com/zieckey/goini

USE_GITLAB=	nodefault
GL_TUPLE=	https://gitlab.howett.net:go:plist:607711222ff2484a487cdec33866b965f4a89653:go_plist/vendor/howett.net/plist

GO_BUILDFLAGS+=	-ldflags="-s -w"

CONFLICTS_INSTALL=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md readme.md

OPTIONS_DEFINE=	DOCS

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} assets

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
