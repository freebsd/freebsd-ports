PORTNAME=	opentelemetry-instrumentation-all
PORTVERSION=	0.89.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	All-in-one instrumentation bundle for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/all \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-instrumentation-active_model_serializers-gitlab>=0.24.0<0.25:devel/rubygem-opentelemetry-instrumentation-active_model_serializers-gitlab \
		rubygem-opentelemetry-instrumentation-anthropic-gitlab>=0.3.0<0.4:devel/rubygem-opentelemetry-instrumentation-anthropic-gitlab \
		rubygem-opentelemetry-instrumentation-aws_lambda-gitlab>=0.6.0<0.7:devel/rubygem-opentelemetry-instrumentation-aws_lambda-gitlab \
		rubygem-opentelemetry-instrumentation-aws_sdk-gitlab>=0.11.0<0.12:devel/rubygem-opentelemetry-instrumentation-aws_sdk-gitlab \
		rubygem-opentelemetry-instrumentation-bunny-gitlab>=0.24.0<0.25:devel/rubygem-opentelemetry-instrumentation-bunny-gitlab \
		rubygem-opentelemetry-instrumentation-concurrent_ruby-gitlab>=0.24.0<0.25:devel/rubygem-opentelemetry-instrumentation-concurrent_ruby-gitlab \
		rubygem-opentelemetry-instrumentation-dalli-gitlab>=0.29.0<0.30:devel/rubygem-opentelemetry-instrumentation-dalli-gitlab \
		rubygem-opentelemetry-instrumentation-delayed_job-gitlab>=0.25.1<0.26:devel/rubygem-opentelemetry-instrumentation-delayed_job-gitlab \
		rubygem-opentelemetry-instrumentation-ethon-gitlab>=0.26.0<0.27:devel/rubygem-opentelemetry-instrumentation-ethon-gitlab \
		rubygem-opentelemetry-instrumentation-excon-gitlab>=0.26.0<0.27:devel/rubygem-opentelemetry-instrumentation-excon-gitlab \
		rubygem-opentelemetry-instrumentation-faraday-gitlab>=0.30.0<0.31:devel/rubygem-opentelemetry-instrumentation-faraday-gitlab \
		rubygem-opentelemetry-instrumentation-grape-gitlab>=0.5.0<0.6:devel/rubygem-opentelemetry-instrumentation-grape-gitlab \
		rubygem-opentelemetry-instrumentation-graphql-gitlab>=0.31.1<0.32:devel/rubygem-opentelemetry-instrumentation-graphql-gitlab \
		rubygem-opentelemetry-instrumentation-grpc-gitlab>=0.4.1<0.5:devel/rubygem-opentelemetry-instrumentation-grpc-gitlab \
		rubygem-opentelemetry-instrumentation-gruf-gitlab>=0.5.0<0.6:devel/rubygem-opentelemetry-instrumentation-gruf-gitlab \
		rubygem-opentelemetry-instrumentation-http-gitlab>=0.27.0<0.28:devel/rubygem-opentelemetry-instrumentation-http-gitlab \
		rubygem-opentelemetry-instrumentation-http_client-gitlab>=0.26.0<0.27:devel/rubygem-opentelemetry-instrumentation-http_client-gitlab \
		rubygem-opentelemetry-instrumentation-httpx-gitlab>=0.5.0<0.6:devel/rubygem-opentelemetry-instrumentation-httpx-gitlab \
		rubygem-opentelemetry-instrumentation-koala-gitlab>=0.23.0<0.24:devel/rubygem-opentelemetry-instrumentation-koala-gitlab \
		rubygem-opentelemetry-instrumentation-lmdb-gitlab>=0.25.0<0.26:devel/rubygem-opentelemetry-instrumentation-lmdb-gitlab \
		rubygem-opentelemetry-instrumentation-mongo-gitlab>=0.25.0<0.26:devel/rubygem-opentelemetry-instrumentation-mongo-gitlab \
		rubygem-opentelemetry-instrumentation-mysql2-gitlab>=0.32.1<0.33:devel/rubygem-opentelemetry-instrumentation-mysql2-gitlab \
		rubygem-opentelemetry-instrumentation-net_http-gitlab>=0.26.0<0.27:devel/rubygem-opentelemetry-instrumentation-net_http-gitlab \
		rubygem-opentelemetry-instrumentation-pg-gitlab>=0.34.1<0.35:devel/rubygem-opentelemetry-instrumentation-pg-gitlab \
		rubygem-opentelemetry-instrumentation-que-gitlab>=0.12.0<0.13:devel/rubygem-opentelemetry-instrumentation-que-gitlab \
		rubygem-opentelemetry-instrumentation-racecar-gitlab>=0.6.0<0.7:devel/rubygem-opentelemetry-instrumentation-racecar-gitlab \
		rubygem-opentelemetry-instrumentation-rack-gitlab>=0.29.0<0.30:devel/rubygem-opentelemetry-instrumentation-rack-gitlab \
		rubygem-opentelemetry-instrumentation-rails-gitlab>=0.39.1<0.40:devel/rubygem-opentelemetry-instrumentation-rails-gitlab \
		rubygem-opentelemetry-instrumentation-rake-gitlab>=0.5.0<0.6:devel/rubygem-opentelemetry-instrumentation-rake-gitlab \
		rubygem-opentelemetry-instrumentation-rdkafka-gitlab>=0.9.0<0.10:devel/rubygem-opentelemetry-instrumentation-rdkafka-gitlab \
		rubygem-opentelemetry-instrumentation-redis-gitlab>=0.28.0<0.29:devel/rubygem-opentelemetry-instrumentation-redis-gitlab \
		rubygem-opentelemetry-instrumentation-resque-gitlab>=0.8.0<0.9:devel/rubygem-opentelemetry-instrumentation-resque-gitlab \
		rubygem-opentelemetry-instrumentation-restclient-gitlab>=0.26.0<0.27:devel/rubygem-opentelemetry-instrumentation-restclient-gitlab \
		rubygem-opentelemetry-instrumentation-ruby_kafka-gitlab>=0.24.0<0.25:devel/rubygem-opentelemetry-instrumentation-ruby_kafka-gitlab \
		rubygem-opentelemetry-instrumentation-sidekiq-gitlab>=0.28.1<0.29:devel/rubygem-opentelemetry-instrumentation-sidekiq-gitlab \
		rubygem-opentelemetry-instrumentation-sinatra-gitlab>=0.28.0<0.29:devel/rubygem-opentelemetry-instrumentation-sinatra-gitlab \
		rubygem-opentelemetry-instrumentation-trilogy-gitlab>=0.65.1<0.66:devel/rubygem-opentelemetry-instrumentation-trilogy-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
