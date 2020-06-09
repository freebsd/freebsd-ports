# $FreeBSD$

PORTNAME=	subfinder
DISTVERSION=	2.3.5
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Subdomain discovery tool that discovers valid subdomains for websites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	projectdiscovery
GH_TUPLE=	\
		alexbrainman:sspi:e580b900e9f5:alexbrainman_sspi/vendor/github.com/alexbrainman/sspi \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:a5ece683394c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:f7b00557c8c4:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:6afb5195e5aa:golang_net/vendor/golang.org/x/net \
		golang:sys:2837fb4f24fe:golang_sys/vendor/golang.org/x/sys \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		jcmturner:aescts:v2.0.0:jcmturner_aescts_v2/vendor/github.com/jcmturner/aescts \
		jcmturner:dnsutils:v2.0.0:jcmturner_dnsutils_v2/vendor/github.com/jcmturner/dnsutils \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:goidentity:v6.0.1:jcmturner_goidentity_v6/vendor/github.com/jcmturner/goidentity \
		jcmturner:gokrb5:v8.2.0:jcmturner_gokrb5_v8/vendor/github.com/jcmturner/gokrb5 \
		jcmturner:rpc:v2.0.2:jcmturner_rpc_v2/vendor/github.com/jcmturner/rpc \
		json-iterator:go:v1.1.9:json_iterator_go/vendor/github.com/json-iterator/go \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lib:pq:v1.6.0:lib_pq/vendor/github.com/lib/pq \
		logrusorgru:aurora:e9ef32dff381:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		m-mizutani:urlscan-go:v1.0.0:m_mizutani_urlscan_go/vendor/github.com/m-mizutani/urlscan-go \
		miekg:dns:v1.1.29:miekg_dns/vendor/github.com/miekg/dns \
		modern-go:concurrent:e0a39a4cb421:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:4b7aa43c6742:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		projectdiscovery:gologger:v1.0.0:projectdiscovery_gologger/vendor/github.com/projectdiscovery/gologger \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		sirupsen:logrus:v1.3.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
