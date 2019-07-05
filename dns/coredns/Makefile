# $FreeBSD$

PORTNAME=	coredns
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.2
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CoreDNS is a DNS server that chains plugins

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	\
		DataDog:dd-trace-go:v1.15.0:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		DataDog:zstd:v1.3.5:datadog_zstd/vendor/github.com/DataDog/zstd \
		Shopify:sarama:v1.21.0:shopify_sarama/vendor/github.com/Shopify/sarama \
		apache:thrift:v0.12.0:apache_thrift/vendor/github.com/apache/thrift \
		aws:aws-sdk-go:v1.20.5:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		caddyserver:caddy:v1.0.1:caddyserver_caddy/vendor/github.com/caddyserver/caddy \
		cenkalti:backoff:v2.1.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		coreos:etcd:v3.3.13:coreos_etcd/vendor/github.com/coreos/etcd \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dnstap:golang-dnstap:2cf77a2b5e11:dnstap_golang_dnstap/vendor/github.com/dnstap/golang-dnstap \
		eapache:go-resiliency:v1.1.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		evanphx:json-patch:v4.1.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		farsightsec:golang-framestream:8a0cb8ba8710:farsightsec_golang_framestream/vendor/github.com/farsightsec/golang-framestream \
		flynn:go-shlex:3f9db97f8568:flynn_go_shlex/vendor/github.com/flynn/go-shlex \
		go-acme:lego:v2.5.0:go_acme_lego/vendor/github.com/go-acme/lego \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-logfmt:logfmt:v0.4.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:ea8f1a30c443:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:b5b0513f8c1b:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:2e65f85255db:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:516e3c20635f:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		google:go-genproto:a7e196e89fd3:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:24818f796faf:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gnostic:v0.2.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-cloud-go:v0.40.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:fe1ba5ce12dd:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		grpc-ecosystem:grpc-opentracing:8e809c8a8645:grpc_ecosystem_grpc_opentracing/vendor/github.com/grpc-ecosystem/grpc-opentracing \
		grpc:grpc-go:v1.21.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		imdario:mergo:v0.3.7:imdario_mergo/vendor/github.com/imdario/mergo \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.6:json_iterator_go/vendor/github.com/json-iterator/go \
		klauspost:cpuid:v1.2.0:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		kr:logfmt:b84e30acd515:kr_logfmt/vendor/github.com/kr/logfmt \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:40a48860b5ab:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:d7deff9243b1:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v11.0.0:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v0.3.3:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:15615b16d372:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:6999998975a7:kubernetes_utils/vendor/k8s.io/utils \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mholt:certmagic:6a42ef9fe8c2:mholt_certmagic/vendor/github.com/mholt/certmagic \
		miekg:dns:v1.1.14:miekg_dns/vendor/github.com/miekg/dns \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		opentracing-contrib:go-observer:a52f23424492:opentracing_contrib_go_observer/vendor/github.com/opentracing-contrib/go-observer \
		opentracing:opentracing-go:v1.1.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		openzipkin-contrib:zipkin-go-opentracing:v0.3.5:openzipkin_contrib_zipkin_go_opentracing/vendor/github.com/openzipkin-contrib/zipkin-go-opentracing \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pierrec:lz4:v2.0.5:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		prometheus:client_golang:v1.0.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.2:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rcrowley:go-metrics:3113b8401b8a:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		square:go-jose:v2.2.2:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		tinylib:msgp:v1.1.0:tinylib_msgp/vendor/github.com/tinylib/msgp
#		openzipkin:zipkin-go-opentracing:v0.3.5:xopenzipkin_zipkin_go_opentracing/vendor/github.com/openzipkin/zipkin-go-opentracing
GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${MKDIR} ${WRKDIR}/coredns-1.5.2/vendor/github.com/openzipkin
	@${LN} -s ${WRKDIR}/coredns-1.5.2/vendor/github.com/openzipkin-contrib/zipkin-go-opentracing ${WRKDIR}/coredns-1.5.2/vendor/github.com/openzipkin/zipkin-go-opentracing

.include <bsd.port.mk>
