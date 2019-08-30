# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-labkit
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Instrumentation for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack52>=5:www/rubygem-actionpack52 \
		rubygem-activesupport52>=5:devel/rubygem-activesupport52 \
		rubygem-grpc>=1.19.0:net/rubygem-grpc \
		rubygem-jaeger-client>=0.10:devel/rubygem-jaeger-client \
		rubygem-opentracing>=0.4:devel/rubygem-opentracing

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
