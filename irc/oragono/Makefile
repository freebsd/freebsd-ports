# $FreeBSD$

PORTNAME=	oragono
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	irc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern IRC server (daemon/ircd) written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	\
		cloudfoundry:bytefmt:cf55d5288a48:cloudfoundry_bytefmt/vendor/code.cloudfoundry.org/bytefmt \
		docopt:docopt.go:ee0de3bc6815:docopt_docopt_go/vendor/github.com/docopt/docopt-go \
		go-asn1-ber:asn1-ber:v1.3.1:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
		go-ldap:ldap:v3.1.7:go_ldap_ldap_v3/vendor/github.com/go-ldap/ldap \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:78000ba7a073:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:bd437916bb0e:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		goshuirc:e-nfa:7071788e3940:goshuirc_e_nfa/vendor/github.com/goshuirc/e-nfa \
		goshuirc:irc-go:57fd157327ac:goshuirc_irc_go/vendor/github.com/goshuirc/irc-go \
		onsi:ginkgo:v1.12.0:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.9.0:onsi_gomega/vendor/github.com/onsi/gomega \
		oragono:confusables:fe1cf31a24b0:oragono_confusables/vendor/github.com/oragono/confusables \
		oragono:go-ident:830550b1d775:oragono_go_ident/vendor/github.com/oragono/go-ident \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tidwall:btree:400434d76274:tidwall_btree/vendor/github.com/tidwall/btree \
		tidwall:buntdb:v1.1.2:tidwall_buntdb/vendor/github.com/tidwall/buntdb \
		tidwall:gjson:v1.3.4:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:grect:ba9a043346eb:tidwall_grect/vendor/github.com/tidwall/grect \
		tidwall:match:v1.0.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tidwall:rtree:6cd427091e0e:tidwall_rtree/vendor/github.com/tidwall/rtree \
		tidwall:tinyqueue:1e39f5511563:tidwall_tinyqueue/vendor/github.com/tidwall/tinyqueue \
		toorop:go-dkim:897ad64a2eeb:toorop_go_dkim/vendor/github.com/toorop/go-dkim

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
