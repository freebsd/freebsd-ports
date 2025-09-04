PORTNAME=	nextdns
PORTVERSION=	1.42.0
DISTVERSIONPREFIX=	v
PORTREVISION=	14
CATEGORIES=	dns security

MAINTAINER=	rs@nextdns.io
COMMENT=	NextDNS DNS53 to DNS over HTTPS proxy
WWW=		https://github.com/nextdns/nextdns

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=3.35:security/ca_root_nss

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	\
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		denisbrodbeck:machineid:v1.0.1:denisbrodbeck_machineid/vendor/github.com/denisbrodbeck/machineid \
		golang:net:v0.8.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		vishvananda:netlink:v1.1.0:vishvananda_netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:2eb08e3e575f:vishvananda_netns/vendor/github.com/vishvananda/netns

GO_TARGET=	.:${PREFIX}/sbin/${PORTNAME}

SUB_FILES=	pkg-message

PLIST_FILES=	sbin/${PORTNAME} \
		"@sample etc/${PORTNAME}.conf.sample"

post-install:
	@${STAGEDIR}${PREFIX}/sbin/${PORTNAME} config > ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
