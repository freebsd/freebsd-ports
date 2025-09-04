PORTNAME=		prometheus-dnssec-exporter
DISTVERSION=		g20220925
PORTREVISION=	24
CATEGORIES=		dns

MAINTAINER=		philip@FreeBSD.org
COMMENT=		DNSSEC exporter for Prometheus
WWW=		https://github.com/chrj/prometheus-dnssec-exporter

LICENSE=		MIT

USES=			go
USE_GITHUB=		yes
USE_RC_SUBR=		dnssec_exporter

GH_ACCOUNT=		chrj
GH_TAGNAME=		33d7d1a
GH_TUPLE=		beorn7:perks:3a771d992973:perks/vendor/github.com/beorn7/perks \
			golang:protobuf:v1.2.0:protobuf/vendor/github.com/golang/protobuf \
			golang:crypto:089bfa567519:net/vendor/golang.org/x/crypto \
			golang:mod:86c51ed26bb4:mod/vendor/golang.org/x/mod \
			golang:net:8be639271d50:net/vendor/golang.org/x/net \
			golang:sys:fb04ddd9f9c8:sys/vendor/golang.org/x/sys \
			golang:tools:v0.1.12:tools/vendor/golang.org/x/tools \
			golang:xerrors:04be3eba64a2:xerrors/vendor/golang.org/x/xerrors \
			matttproud:golang_protobuf_extensions:v1.0.1:extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
			miekg:dns:v1.1.50:dns/vendor/github.com/miekg/dns \
			naoina:go-stringutil:v0.1.0:go_stringutil/vendor/github.com/naoina/go-stringutil \
			naoina:toml:v0.1.1:toml/vendor/github.com/naoina/toml \
			prometheus:client_golang:v0.8.0:client_golang/vendor/github.com/prometheus/client_golang \
			prometheus:client_model:5c3871d89910:client_model/vendor/github.com/prometheus/client_model \
			prometheus:common:c7de2306084e:common/vendor/github.com/prometheus/common \
			prometheus:procfs:418d78d0b9a7:procfs/vendor/github.com/prometheus/procfs

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
