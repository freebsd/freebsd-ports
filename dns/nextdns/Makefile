PORTNAME=	nextdns
PORTVERSION=	1.32.2
CATEGORIES=	dns security

MAINTAINER=	rs@nextdns.io
COMMENT=	NextDNS DNS53 to DNS over HTTPS proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=3.35:security/ca_root_nss

USES=		go:modules
PLIST_FILES=	sbin/nextdns
USE_GITHUB=	yes
GO_TARGET=	.:${PREFIX}/sbin/nextdns
GH_ACCOUNT=	nextdns
GH_TAGNAME=	v1.32.2
GH_TUPLE=	\
		Microsoft:go-winio:v0.4.19:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		denisbrodbeck:machineid:v1.0.1:denisbrodbeck_machineid/vendor/github.com/denisbrodbeck/machineid \
		golang:crypto:83a5a9bb288b:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:4e50805a0758:golang_net/vendor/golang.org/x/net \
		golang:sys:33663a62ff08:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		lucas-clemente:quic-go:v0.20.1:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qpack:v0.2.1:marten_seemann_qpack/vendor/github.com/marten-seemann/qpack \
		marten-seemann:qtls-go1-15:v0.1.4:marten_seemann_qtls_go1_15/vendor/github.com/marten-seemann/qtls-go1-15 \
		marten-seemann:qtls-go1-16:v0.1.3:marten_seemann_qtls_go1_16/vendor/github.com/marten-seemann/qtls-go1-16

SUB_FILES=	pkg-message

.include <bsd.port.mk>
