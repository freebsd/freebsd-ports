# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	gitlab-labkit
PORTVERSION=	0.23.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Instrumentation for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=5<7:www/rubygem-actionpack61 \
		rubygem-activesupport61>=5<7:devel/rubygem-activesupport61 \
		rubygem-grpc142>=1.37:net/rubygem-grpc142 \
		rubygem-jaeger-client>=1.1.0<1.2:devel/rubygem-jaeger-client \
		rubygem-opentracing>=0.4<1.0:devel/rubygem-opentracing \
		rubygem-pg_query>=2.1<3:databases/rubygem-pg_query \
		rubygem-redis>3.0.0<5.0.0:databases/rubygem-redis

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
