PORTNAME=	opentelemetry-instrumentation-all
PORTVERSION=	0.85.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	All-in-one instrumentation bundle for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/all \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-instrumentation-active_model_serializers>=0.23.0<1:devel/rubygem-opentelemetry-instrumentation-active_model_serializers \
		rubygem-opentelemetry-instrumentation-anthropic>=0.2.0<0.3:devel/rubygem-opentelemetry-instrumentation-anthropic \
		rubygem-opentelemetry-instrumentation-aws_lambda>=0.5.0<0.6:devel/rubygem-opentelemetry-instrumentation-aws_lambda \
		rubygem-opentelemetry-instrumentation-aws_sdk>=0.9.0<0.11:devel/rubygem-opentelemetry-instrumentation-aws_sdk \
		rubygem-opentelemetry-instrumentation-bunny>=0.23.0<0.24:devel/rubygem-opentelemetry-instrumentation-bunny \
		rubygem-opentelemetry-instrumentation-concurrent_ruby>=0.23.0<0.24:devel/rubygem-opentelemetry-instrumentation-concurrent_ruby \
		rubygem-opentelemetry-instrumentation-dalli>=0.28.0<0.29:devel/rubygem-opentelemetry-instrumentation-dalli \
		rubygem-opentelemetry-instrumentation-delayed_job>=0.24.0<0.25:devel/rubygem-opentelemetry-instrumentation-delayed_job \
		rubygem-opentelemetry-instrumentation-ethon>=0.24.0<0.25:devel/rubygem-opentelemetry-instrumentation-ethon \
		rubygem-opentelemetry-instrumentation-excon>=0.25.0<0.26:devel/rubygem-opentelemetry-instrumentation-excon \
		rubygem-opentelemetry-instrumentation-faraday>=0.29.0<0.30:devel/rubygem-opentelemetry-instrumentation-faraday \
		rubygem-opentelemetry-instrumentation-grape>=0.4.0<0.5:devel/rubygem-opentelemetry-instrumentation-grape \
		rubygem-opentelemetry-instrumentation-graphql>=0.30.0<0.31:devel/rubygem-opentelemetry-instrumentation-graphql \
		rubygem-opentelemetry-instrumentation-grpc>=0.3.0<0.4:devel/rubygem-opentelemetry-instrumentation-grpc \
		rubygem-opentelemetry-instrumentation-gruf>=0.4.0<0.5:devel/rubygem-opentelemetry-instrumentation-gruf \
		rubygem-opentelemetry-instrumentation-http>=0.26.0<0.27:devel/rubygem-opentelemetry-instrumentation-http \
		rubygem-opentelemetry-instrumentation-http_client>=0.25.0<0.26:devel/rubygem-opentelemetry-instrumentation-http_client \
		rubygem-opentelemetry-instrumentation-httpx>=0.4.0<0.5:devel/rubygem-opentelemetry-instrumentation-httpx \
		rubygem-opentelemetry-instrumentation-koala>=0.22.0<0.23:devel/rubygem-opentelemetry-instrumentation-koala \
		rubygem-opentelemetry-instrumentation-lmdb>=0.24.0<0.25:devel/rubygem-opentelemetry-instrumentation-lmdb \
		rubygem-opentelemetry-instrumentation-mongo>=0.24.0<0.25:devel/rubygem-opentelemetry-instrumentation-mongo \
		rubygem-opentelemetry-instrumentation-mysql2>=0.30.0<0.31:devel/rubygem-opentelemetry-instrumentation-mysql2 \
		rubygem-opentelemetry-instrumentation-net_http>=0.25.0<0.26:devel/rubygem-opentelemetry-instrumentation-net_http \
		rubygem-opentelemetry-instrumentation-pg>=0.31.0<0.32:devel/rubygem-opentelemetry-instrumentation-pg \
		rubygem-opentelemetry-instrumentation-que>=0.10.0<0.11:devel/rubygem-opentelemetry-instrumentation-que \
		rubygem-opentelemetry-instrumentation-racecar>=0.5.0<0.6:devel/rubygem-opentelemetry-instrumentation-racecar \
		rubygem-opentelemetry-instrumentation-rack>=0.28.0<0.29:devel/rubygem-opentelemetry-instrumentation-rack \
		rubygem-opentelemetry-instrumentation-rails>=0.38.0<0.39:devel/rubygem-opentelemetry-instrumentation-rails \
		rubygem-opentelemetry-instrumentation-rake>=0.4.0<0.5:devel/rubygem-opentelemetry-instrumentation-rake \
		rubygem-opentelemetry-instrumentation-rdkafka>=0.8.0<0.9:devel/rubygem-opentelemetry-instrumentation-rdkafka \
		rubygem-opentelemetry-instrumentation-redis>=0.27.0<0.28:devel/rubygem-opentelemetry-instrumentation-redis \
		rubygem-opentelemetry-instrumentation-resque>=0.7.0<0.8:devel/rubygem-opentelemetry-instrumentation-resque \
		rubygem-opentelemetry-instrumentation-restclient>=0.25.0<0.26:devel/rubygem-opentelemetry-instrumentation-restclient \
		rubygem-opentelemetry-instrumentation-ruby_kafka>=0.23.0<0.24:devel/rubygem-opentelemetry-instrumentation-ruby_kafka \
		rubygem-opentelemetry-instrumentation-sidekiq>=0.27.0<0.28:devel/rubygem-opentelemetry-instrumentation-sidekiq \
		rubygem-opentelemetry-instrumentation-sinatra>=0.27.0<0.28:devel/rubygem-opentelemetry-instrumentation-sinatra \
		rubygem-opentelemetry-instrumentation-trilogy>=0.63.0<0.64:devel/rubygem-opentelemetry-instrumentation-trilogy

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
