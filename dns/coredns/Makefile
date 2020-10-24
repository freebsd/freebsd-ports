# $FreeBSD$

PORTNAME=	coredns
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DNS server that chains plugins

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	\
		Azure:azure-sdk-for-go:v40.6.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		DataDog:datadog-go:v3.5.0:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		DataDog:dd-trace-go:v1.27.1:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		aws:aws-sdk-go:v1.35.9:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cenkalti:backoff:v4.1.0:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		census-instrumentation:opencensus-go:v0.22.3:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coredns:caddy:v1.1.0:coredns_caddy/vendor/github.com/coredns/caddy \
		coreos:go-systemd:v22.0.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		dnstap:golang-dnstap:v0.2.2:dnstap_golang_dnstap/vendor/github.com/dnstap/golang-dnstap \
		etcd-io:etcd:221f0cc107cb:etcd_io_etcd/vendor/go.etcd.io/etcd \
		evanphx:json-patch:v4.9.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		farsightsec:golang-framestream:v0.3.0:farsightsec_golang_framestream/vendor/github.com/farsightsec/golang-framestream \
		flynn:go-shlex:3f9db97f8568:flynn_go_shlex/vendor/github.com/flynn/go-shlex \
		form3tech-oss:jwt-go:v3.2.2:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-logr:logr:v0.2.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:7f63de1d35b0:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:ab3426394381:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:e3ed0017c211:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:cb27e3aa2013:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.4.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.29.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.56.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc-ecosystem:grpc-opentracing:8e809c8a8645:grpc_ecosystem_grpc_opentracing/vendor/github.com/grpc-ecosystem/grpc-opentracing \
		grpc:grpc-go:v1.29.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		imdario:mergo:v0.3.9:imdario_mergo/vendor/github.com/imdario/mergo \
		infobloxopen:go-trees:2af4e13f9062:infobloxopen_go_trees/vendor/github.com/infobloxopen/go-trees \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.19.2:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.19.2:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.19.2:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v2.3.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:6aeccd4b50c6:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:d5654de09c73:kubernetes_utils/vendor/k8s.io/utils \
		kubernetes-sigs:structured-merge-diff:v4.0.1:sigs_k8s_io_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.34:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		opentracing-contrib:go-observer:a52f23424492:opentracing_contrib_go_observer/vendor/github.com/opentracing-contrib/go-observer \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		openzipkin-contrib:zipkin-go-opentracing:v0.4.5:openzipkin_contrib_zipkin_go_opentracing/vendor/github.com/openzipkin-contrib/zipkin-go-opentracing \
		openzipkin:zipkin-go:v0.2.2:openzipkin_zipkin_go/vendor/github.com/openzipkin/zipkin-go \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.8.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.14.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.2.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.24.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		tinylib:msgp:v1.1.2:tinylib_msgp/vendor/github.com/tinylib/msgp \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.14.1:uber_go_zap/vendor/go.uber.org/zap
GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^[0-9]*\.[0-9]*\.[0-9]*$$ # otherwise it picks up the deleted tag v011

post-extract: # both vendor/k8s.io/klog and vendor/k8s.io/klog/v2 are expected
	cd ${WRKSRC}/vendor/k8s.io/klog && ${LN} -s . v2

.include <bsd.port.mk>
