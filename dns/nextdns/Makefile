# $FreeBSD$

PORTNAME=	nextdns
PORTVERSION=	1.5.7
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
GH_TAGNAME=	v1.4.25
GH_TUPLE=	\
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		denisbrodbeck:machineid:v1.0.1:denisbrodbeck_machineid/vendor/github.com/denisbrodbeck/machineid \
		golang:crypto:9ee001bba392:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:a882066a44e0:golang_net/vendor/golang.org/x/net \
		golang:sys:52ab43148777:golang_sys/vendor/golang.org/x/sys \
		grandcat:zeroconf:85eadb44205c:grandcat_zeroconf/vendor/github.com/grandcat/zeroconf \
		miekg:dns:v1.1.22:miekg_dns/vendor/github.com/miekg/dns \
		rs:service:b1a37fd90075:rs_service/vendor/github.com/kardianos/service

SUB_FILES=	pkg-message

.include <bsd.port.mk>
