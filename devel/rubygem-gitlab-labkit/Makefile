# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-labkit
PORTVERSION=	0.12.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Instrumentation for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=5<6.1.0:www/rubygem-actionpack60 \
		rubygem-activesupport60>=5<6.1.0:devel/rubygem-activesupport60 \
		rubygem-grpc124>=1.19:net/rubygem-grpc124 \
		rubygem-jaeger-client>=0.10<1.0:devel/rubygem-jaeger-client \
		rubygem-opentracing>=0.4<1.0:devel/rubygem-opentracing \
		rubygem-redis>3.0.0<5.0.0:databases/rubygem-redis

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
