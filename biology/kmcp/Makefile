PORTNAME=	kmcp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Accurate metagenomic profiling & fast large-scale genome searching

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	undefined: andInplaceFuncs, undefined: andFuncs, see https://github.com/shenwei356/pand/issues/4
BROKEN_i386=	undefined: andInplaceFuncs, undefined: andFuncs, see https://github.com/shenwei356/pand/issues/4

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	shenwei356
GH_TUPLE=	\
		VividCortex:ewma:v1.1.1:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		acarl005:stripansi:5a71ef0e047d:acarl005_stripansi/vendor/github.com/acarl005/stripansi \
		clausecker:pospop:677120eb417c:clausecker_pospop/vendor/github.com/clausecker/pospop \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		edsrzf:mmap-go:v1.1.0:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sys:1d35b9e2eb4e:golang_sys/vendor/golang.org/x/sys \
		grailbio:base:v0.0.10:grailbio_base/vendor/github.com/grailbio/base \
		iafan:cwalk:586a8832a711:iafan_cwalk/vendor/github.com/iafan/cwalk \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		klauspost:compress:v1.15.0:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:pgzip:v1.2.5:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		shenwei356:bio:v0.7.0:shenwei356_bio/vendor/github.com/shenwei356/bio \
		shenwei356:breader:v0.3.1:shenwei356_breader/vendor/github.com/shenwei356/breader \
		shenwei356:go-logging:c6b9702d88ba:shenwei356_go_logging/vendor/github.com/shenwei356/go-logging \
		shenwei356:kmers:v0.1.0:shenwei356_kmers/vendor/github.com/shenwei356/kmers \
		shenwei356:natsort:600d539c017d:shenwei356_natsort/vendor/github.com/shenwei356/natsort \
		shenwei356:pand:v0.0.5:shenwei356_pand/vendor/github.com/shenwei356/pand \
		shenwei356:unik:v5.0.1:shenwei356_unik_v5/vendor/github.com/shenwei356/unik/v5 \
		shenwei356:util:v0.5.0:shenwei356_util/vendor/github.com/shenwei356/util \
		shenwei356:xopen:v0.2.1:shenwei356_xopen/vendor/github.com/shenwei356/xopen \
		spf13:cobra:v1.4.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		tatsushid:go-prettytable:ed2d14c29939:tatsushid_go_prettytable/vendor/github.com/tatsushid/go-prettytable \
		twotwotwo:sorts:bf5c1f2b8553:twotwotwo_sorts/vendor/github.com/twotwotwo/sorts \
		ulikunitz:xz:v0.5.10:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		vbauerster:mpb:v5.4.0:vbauerster_mpb_v5/vendor/github.com/vbauerster/mpb/v5 \
		will-rowe:nthash:v0.4.0:will_rowe_nthash/vendor/github.com/will-rowe/nthash \
		zeebo:wyhash:v0.0.1:zeebo_wyhash/vendor/github.com/zeebo/wyhash \
		zeebo:xxh3:v0.13.0:zeebo_xxh3/vendor/github.com/zeebo/xxh3

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./kmcp

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
