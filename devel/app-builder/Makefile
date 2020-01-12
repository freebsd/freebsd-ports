# $FreeBSD$

PORTNAME=	app-builder
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.2
CATEGORIES=	devel

MAINTAINER=	tagattie@yandex.com
COMMENT=	Generic helper tool to build app in a distributable format

LICENSE=	MIT

BUILD_DEPENDS=	go-bindata:devel/go-bindata

USES=		gmake go:modules

USE_GITHUB=	yes
USE_GITLAB=	nodefault

GH_ACCOUNT=	develar
GH_TUPLE=	aclements:go-rabin:d0b643ea1a4c:aclements_go_rabin/vendor/github.com/aclements/go-rabin \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/github.com/alecthomas/kingpin \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:c3de453c63f4:alecthomas_units/vendor/github.com/alecthomas/units \
		alessio:shellescape:52074bc9df61:alessio_shellescape/vendor/gopkg.in/alessio/shellescape.v1 \
		aws:aws-sdk-go:v1.21.3:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		biessek:golang-ico:d348d9ea4670:biessek_golang_ico/vendor/github.com/biessek/golang-ico \
		develar:errors:v0.9.0:develar_errors/vendor/github.com/develar/errors \
		develar:go-fs-util:69a2d4542206:develar_go_fs_util/vendor/github.com/develar/go-fs-util \
		develar:go-pkcs12:54baa4f32c6a:develar_go_pkcs12/vendor/github.com/develar/go-pkcs12 \
		disintegration:imaging:v1.6.0:disintegration_imaging/vendor/github.com/disintegration/imaging \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:image:d6a02ce849c9:golang_image/vendor/golang.org/x/image \
		golang:net:ca1201d0de80:golang_net/vendor/golang.org/x/net \
		golang:sys:fae7ac547cb7:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		hpcloud:tail:v1.0.0:hpcloud_tail/vendor/github.com/hpcloud/tail \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.6:json_iterator_go/vendor/github.com/json-iterator/go \
		jsummers:gobmp:e2ba15ffa76e:jsummers_gobmp/vendor/github.com/jsummers/gobmp \
		mattn:go-colorable:v0.1.2:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.8:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mcuadros:go-version:92cdf37c5b75:mcuadros_go_version/vendor/github.com/mcuadros/go-version \
		minio:blake2b-simd:3f5f724cb5b1:minio_blake2b_simd/vendor/github.com/minio/blake2b-simd \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		onsi:ginkgo:v1.8.0:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.5.0:onsi_gomega/vendor/github.com/onsi/gomega \
		oxtoacart:bpool:03653db5a59c:oxtoacart_bpool/vendor/github.com/oxtoacart/bpool \
		phayes:permbits:39d7c581d2ee:phayes_permbits/vendor/github.com/phayes/permbits \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:xattr:v0.4.1:pkg_xattr/vendor/github.com/pkg/xattr \
		segmentio:ksuid:v1.0.2:segmentio_ksuid/vendor/github.com/segmentio/ksuid \
		uber-go:atomic:v1.4.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.1.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.10.0:uber_go_zap/vendor/go.uber.org/zap \
		zieckey:goini:0da17d361d26:zieckey_goini/vendor/github.com/zieckey/goini

GL_TUPLE=	https://gitlab.howett.net:go:plist:591f970eefbbeb04d7b37f334a0c4c3256e32876:go_plist/vendor/howett.net/plist

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	readme.md

OPTIONS_DEFINE=	DOCS

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} assets

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
