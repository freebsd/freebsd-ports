# $FreeBSD$

PORTNAME=	mutagen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	devel net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Continuous multidirectional synchronization for remote development

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	havoc-io
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Microsoft:go-winio:v0.4.14:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		bmatcuk:doublestar:v1.1.1:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eknkc:basex:v1.0.0:eknkc_basex/vendor/github.com/eknkc/basex \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:e9b2fee46413:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:c0dbc17a3553:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:d101bd2416d5:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		grpc:grpc-go:v1.27.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:yamux:df201c70410d:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		hectane:go-acl:e28f47eff0c4:hectane_go_acl/vendor/github.com/hectane/go-acl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kubernetes:apimachinery:6a84e37a896d:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:klog:v0.3.0:kubernetes_klog/vendor/k8s.io/klog \
		lucas-clemente:quic-go:907071221cf9:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qtls:v0.2.3:marten_seemann_qtls/vendor/github.com/marten-seemann/qtls \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mutagen-io:fsevents:10556809b434:mutagen_io_fsevents/vendor/github.com/mutagen-io/fsevents \
		mutagen-io:gopass:9a121bec1ae7:mutagen_io_gopass/vendor/github.com/mutagen-io/gopass \
		pion:datachannel:v1.4.14:pion_datachannel/vendor/github.com/pion/datachannel \
		pion:dtls:v2.0.0-rc.3:pion_dtls/vendor/github.com/pion/dtls/v2 \
		pion:ice:v0.7.6:pion_ice/vendor/github.com/pion/ice \
		pion:logging:v0.2.2:pion_logging/vendor/github.com/pion/logging \
		pion:mdns:v0.0.4:pion_mdns/vendor/github.com/pion/mdns \
		pion:quic:v0.1.1:pion_quic/vendor/github.com/pion/quic \
		pion:rtcp:v1.2.1:pion_rtcp/vendor/github.com/pion/rtcp \
		pion:rtp:v1.1.4:pion_rtp/vendor/github.com/pion/rtp \
		pion:sctp:v1.7.4:pion_sctp/vendor/github.com/pion/sctp \
		pion:sdp:v2.3.1:pion_sdp/vendor/github.com/pion/sdp/v2 \
		pion:srtp:v1.2.6:pion_srtp/vendor/github.com/pion/srtp \
		pion:stun:v0.3.3:pion_stun/vendor/github.com/pion/stun \
		pion:transport:v0.8.10:pion_transport/vendor/github.com/pion/transport \
		pion:turn:v1.4.0:pion_turn/vendor/github.com/pion/turn \
		pion:webrtc:v2.1.18:pion_webrtc/vendor/github.com/pion/webrtc/v2 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		shibukawa:extstat:4113c04d0977:shibukawa_extstat/vendor/github.com/shibukawa/extstat \
		spf13:cobra:b04b5bfc50cb:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag

GO_TARGET=	./cmd/mutagen \
		./cmd/mutagen-agent

PLIST_FILES=	bin/mutagen \
		bin/mutagen-agent

.include <bsd.port.mk>
