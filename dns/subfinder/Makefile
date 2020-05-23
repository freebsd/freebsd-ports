# $FreeBSD$

PORTNAME=	subfinder
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.4
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Subdomain discovery tool that discovers valid subdomains for websites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	projectdiscovery
GH_TUPLE=	\
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:4206685974f28e3178b35fa198a59899aa4dee3a:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.7:go_yaml_yaml_1/vendor/gopkg.in/yaml.v2 \
		golang:crypto:86a70503ff7e82ffc18c7b0de83db35da4791e6a:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:5ee1b9f4859acd2e99987ef94ec7a58427c53bef:golang_net/vendor/golang.org/x/net \
		golang:sys:ce4227a45e2eb77e5c847278dcc6a626742e2945:golang_sys/vendor/golang.org/x/sys \
		json-iterator:go:v1.1.8:json_iterator_go/vendor/github.com/json-iterator/go \
		konsorten:go-windows-terminal-sequences:v1.0.2:go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lib:pq:9eb3fc8:pq/vendor/github.com/lib/pq \
		logrusorgru:aurora:21d75270181e0436fee7bd58b991c212cf309068:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		m-mizutani:urlscan-go:v1.0.0:m_mizutani_urlscan_go/vendor/github.com/m-mizutani/urlscan-go \
		miekg:dns:v1.1.22:miekg_dns/vendor/github.com/miekg/dns \
		modern-go:concurrent:bacd9c7ef1dd9b15be4a9909b8ac7a4e313eec94:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:4b7aa43c6742a2c18fdef89dd197aaae7dac7ccd:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		projectdiscovery:gologger:v1.0.0:projectdiscovery_gologger/vendor/github.com/projectdiscovery/gologger \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.4.0:testify/vendor/github.com/stretchr/testify

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
