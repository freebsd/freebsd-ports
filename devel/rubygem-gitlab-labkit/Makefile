PORTNAME=	gitlab-labkit
PORTVERSION=	1.3.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Instrumentation for GitLab
WWW=		https://about.gitlab.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack-gitlab>=5<8.1:www/rubygem-actionpack-gitlab \
		rubygem-activesupport-gitlab>=5<8.1:devel/rubygem-activesupport-gitlab \
		rubygem-google-protobuf3>=3.25<5:devel/rubygem-google-protobuf3 \
		rubygem-grpc-gitlab>=1.75:net/rubygem-grpc-gitlab \
		rubygem-jaeger-client>=1.1.0<1.2:devel/rubygem-jaeger-client \
		rubygem-json_schemer>=2.3.0<3:devel/rubygem-json_schemer \
		rubygem-openssl3>=3.3.2<3.4:security/rubygem-openssl3 \
		rubygem-opentracing>=0.4<1:devel/rubygem-opentracing \
		rubygem-pg_query>=6.1.0<7:databases/rubygem-pg_query \
		rubygem-prometheus-client-mmap>=1.2.9<2:devel/rubygem-prometheus-client-mmap \
		rubygem-redis-gitlab>3.0.0<6.0.0:databases/rubygem-redis-gitlab

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/labkit-logging

.include <bsd.port.mk>
