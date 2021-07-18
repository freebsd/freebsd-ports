PORTNAME=	ergo
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0
CATEGORIES=	irc
PKGNAMESUFFIX=	-irc-server

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern IRC server (daemon/ircd) written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	ergochat
GH_TUPLE=	\
		GehirnInc:crypt:bb7000b8a962:gehirninc_crypt/vendor/github.com/GehirnInc/crypt \
		cloudfoundry:bytefmt:cf55d5288a48:cloudfoundry_bytefmt/vendor/code.cloudfoundry.org/bytefmt \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		docopt:docopt.go:ee0de3bc6815:docopt_docopt_go/vendor/github.com/docopt/docopt-go \
		ergochat:confusables:4ab98ab61fb1:ergochat_confusables/vendor/github.com/ergochat/confusables \
		ergochat:go-ident:830550b1d775:ergochat_go_ident/vendor/github.com/ergochat/go-ident \
		ergochat:websocket:v1.4.2-oragono1:ergochat_websocket/vendor/github.com/gorilla/websocket \
		go-sql-driver:mysql:v1.6.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-test:deep:v1.0.6:go_test_deep/vendor/github.com/go-test/deep \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:4f45737414dc:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:f84b799fce68:golang_sys/vendor/golang.org/x/sys \
		golang:term:7de9c90e9dd1:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		goshuirc:irc-go:bdc2c2cd2fef:goshuirc_irc_go/vendor/github.com/goshuirc/irc-go \
		onsi:ginkgo:v1.12.0:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.9.0:onsi_gomega/vendor/github.com/onsi/gomega \
		oragono:confusables:4ab98ab61fb1:oragono_confusables \
		oragono:go-ident:830550b1d775:oragono_go_ident \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tidwall:btree:v0.4.2:tidwall_btree/vendor/github.com/tidwall/btree \
		tidwall:buntdb:v1.2.3:tidwall_buntdb/vendor/github.com/tidwall/buntdb \
		tidwall:gjson:v1.7.4:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:grect:v0.1.1:tidwall_grect/vendor/github.com/tidwall/grect \
		tidwall:match:v1.0.3:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.1.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tidwall:rtred:v0.1.2:tidwall_rtred/vendor/github.com/tidwall/rtred \
		tidwall:rtree:32188eeb08a8:tidwall_rtree/vendor/github.com/tidwall/rtree \
		tidwall:tinyqueue:v0.1.1:tidwall_tinyqueue/vendor/github.com/tidwall/tinyqueue \
		toorop:go-dkim:e1cd1a0a5208:toorop_go_dkim/vendor/github.com/toorop/go-dkim

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/oragono
	@${RLN} ${WRKSRC_ergochat_confusables} ${WRKSRC}/vendor/github.com/oragono/confusables
	@${RLN} ${WRKSRC_ergochat_go_ident} ${WRKSRC}/vendor/github.com/oragono/go-ident

.include <bsd.port.mk>
