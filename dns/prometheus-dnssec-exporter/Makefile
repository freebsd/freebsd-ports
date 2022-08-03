PORTNAME=		prometheus-dnssec-exporter
DISTVERSION=		g20181110
PORTREVISION=	4
CATEGORIES=		dns

MAINTAINER=		philip@FreeBSD.org
COMMENT=		DNSSEC exporter for Prometheus

LICENSE=		MIT

USES=			go
USE_GITHUB=		yes
USE_RC_SUBR=		dnssec_exporter

GH_ACCOUNT=		chrj
GH_TAGNAME=		caa7d89
GH_TUPLE=		beorn7:perks:v1.0.1:perks/vendor/github.com/beorn7/perks \
			cespare:xxhash:v1.1.0:xxhash/vendor/github.com/cespare/xxhash \
			cespare:xxhash:v2.1.2:xxhash/vendor/github.com/cespare/xxhash/v2 \
			golang:crypto:089bfa567519:crypto/vendor/golang.org/x/crypto \
			golang:net:4a448f8816b3:net/vendor/golang.org/x/net \
			golang:sys:39c9dd37992c:sys/vendor/golang.org/x/sys \
			golang:protobuf:v1.5.2:protobuf/vendor/github.com/golang/protobuf \
			matttproud:golang_protobuf_extensions:v1.0.1:extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
			miekg:dns:v1.0.12:dns/vendor/github.com/miekg/dns \
			naoina:go-stringutil:v0.1.0:go_stringutil/vendor/github.com/naoina/go-stringutil \
			naoina:toml:v0.1.1:toml/vendor/github.com/naoina/toml \
			prometheus:client_golang:v1.11.0:client_golang/vendor/github.com/prometheus/client_golang \
			prometheus:client_model:v0.2.0:client_model/vendor/github.com/prometheus/client_model \
			prometheus:common:v0.32.1:common/vendor/github.com/prometheus/common \
			prometheus:procfs:v0.7.3:procfs/vendor/github.com/prometheus/procfs \
			protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

GO_PKGNAME=		github.com/${GH_ACCOUNT}/${PORTNAME}

USERS=			nobody
GROUPS=			nobody

SUB_FILES=		pkg-message
SUB_LIST=		USERS=${USERS} GROUPS=${GROUPS}

PLIST_FILES=		bin/prometheus-dnssec-exporter \
			"@sample etc/prometheus-dnssec-checks.sample"

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/main.go

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.sample \
		${STAGEDIR}${PREFIX}/etc/prometheus-dnssec-checks.sample

.include <bsd.port.mk>
