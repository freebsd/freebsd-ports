PORTNAME=	gitlab-labkit
PORTVERSION=	0.39.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Instrumentation for GitLab
WWW=		https://about.gitlab.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack-gitlab>=5<8.1:www/rubygem-actionpack-gitlab \
		rubygem-activesupport-gitlab>=5<8.1:devel/rubygem-activesupport-gitlab \
		rubygem-google-protobuf3>=3<4:devel/rubygem-google-protobuf3 \
		rubygem-grpc-gitlab>=1.62:net/rubygem-grpc-gitlab \
		rubygem-jaeger-client>=1.1.0<1.2:devel/rubygem-jaeger-client \
		rubygem-opentracing>=0.4<1:devel/rubygem-opentracing \
		rubygem-pg_query>=6.1.0<7:databases/rubygem-pg_query \
		rubygem-prometheus-client-mmap>=1.2.8<1.3:devel/rubygem-prometheus-client-mmap \
		rubygem-redis>3.0.0<6.0.0:databases/rubygem-redis

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
