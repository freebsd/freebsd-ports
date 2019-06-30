# $FreeBSD$

PORTNAME=	coredns
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CoreDNS is a DNS server that chains plugins

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	\
		DataDog:dd-trace-go:v1.15.0:datadog_dd_trace_go_v0/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		DataDog:zstd:v1.3.5:datadog_zstd/vendor/github.com/DataDog/zstd \
		Shopify:sarama:v1.21.0:shopify_sarama/vendor/github.com/Shopify/sarama \
		apache:thrift:v0.12.0:apache_thrift/vendor/github.com/apache/thrift \
		aws:aws-sdk-go:v1.14.17:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:3a771d992973:beorn7_perks/vendor/github.com/beorn7/perks \
		coreos:etcd:v3.3.11:coreos_etcd/vendor/github.com/coreos/etcd \
		datadog:dd-trace-go:2761701:datadog_dd_trace_go/vendor/github.com/DataDog/dd-trace-go \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dnstap:golang-dnstap:2cf77a2b5e11:dnstap_golang_dnstap/vendor/github.com/dnstap/golang-dnstap \
		eapache:go-resiliency:v1.1.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		evanphx:json-patch:v4.1.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		farsightsec:golang-framestream:8a0cb8ba8710:farsightsec_golang_framestream/vendor/github.com/farsightsec/golang-framestream \
		flynn:go-shlex:3f9db97f8568:flynn_go_shlex/vendor/github.com/flynn/go-shlex \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/github.com/go-ini/ini \
		go-logfmt:logfmt:v0.4.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.2.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c2843e01d9a2:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:74de082e2cca:golang_net/vendor/golang.org/x/net \
		golang:oauth2:d2e6202438be:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.2.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:2e65f85255db:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:a34e9553db1e:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		google:btree:4030bb1f1f0c:google_btree/vendor/github.com/google/btree \
		google:go-genproto:c66870c02cf8:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-cmp:v0.3.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:gofuzz:24818f796faf:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gnostic:v0.2.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-cloud-go:v0.28.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:fe1ba5ce12dd:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gregjones:httpcache:3befbb6ad0cc:gregjones_httpcache/vendor/github.com/gregjones/httpcache \
		grpc-ecosystem:grpc-opentracing:8e809c8a8645:grpc_ecosystem_grpc_opentracing/vendor/github.com/grpc-ecosystem/grpc-opentracing \
		grpc:grpc-go:v1.19.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		imdario:mergo:v0.3.7:imdario_mergo/vendor/github.com/imdario/mergo \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.5:json_iterator_go/vendor/github.com/json-iterator/go \
		kr:logfmt:b84e30acd515:kr_logfmt/vendor/github.com/kr/logfmt \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mholt:caddy:v1.0.0:mholt_caddy/vendor/github.com/mholt/caddy \
		miekg:dns:v1.1.8:miekg_dns/vendor/github.com/miekg/dns \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		opentracing-contrib:go-observer:a52f23424492:opentracing_contrib_go_observer/vendor/github.com/opentracing-contrib/go-observer \
		opentracing:opentracing-go:v1.0.2:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		openzipkin:zipkin-go-opentracing:v0.3.4:openzipkin_zipkin_go_opentracing/vendor/github.com/openzipkin/zipkin-go-opentracing \
		peterbourgon:diskv:v2.0.1:peterbourgon_diskv/vendor/github.com/peterbourgon/diskv \
		philhofer:fwd:v1.0.0:fwd/vendor/github.com/philhofer/fwd \
		pierrec:lz4:v2.0.5:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		prometheus:client_golang:v0.9.2:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:5c3871d89910:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:4724e9255275:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:1dc9a6cbc91a:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rcrowley:go-metrics:3113b8401b8a:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		tinylib:msgp:v1.1.0:msgp/vendor/github.com/tinylib/msgp \
		ugorji:go:c4a1c341dc93:ugorji_go/vendor/github.com/ugorji/go \
		kubernetes:api:kubernetes-1.15.1-beta.0:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:kubernetes-1.15.1-beta.0:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:kubernetes-1.15.1-beta.0:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v0.3.3:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:db7b694:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:c55fbcf:kubernetes_utils/vendor/k8s.io/utils \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_yaml/vendor/sigs.k8s.io/yaml

GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
