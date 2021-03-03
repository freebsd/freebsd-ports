# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-labkit
PORTVERSION=	0.15.0
PORTREVISION=	0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Instrumentation for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=5<7:www/rubygem-actionpack60 \
		rubygem-activesupport60>=5<7:devel/rubygem-activesupport60 \
		rubygem-gitlab-pg_query>=1.3<2:databases/rubygem-gitlab-pg_query \
		rubygem-grpc130>=1.19<2:net/rubygem-grpc130 \
		rubygem-jaeger-client>=1.1<2:devel/rubygem-jaeger-client \
		rubygem-opentracing>=0.4<1.0:devel/rubygem-opentracing \
		rubygem-pg_query>=1.3<2:databases/rubygem-pg_query \
		rubygem-redis>3.0.0<5.0.0:databases/rubygem-redis

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
