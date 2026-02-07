PORTNAME=	gitlab-sdk
PORTVERSION=	0.3.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client side Ruby SDK for GitLab Application services
WWW=		https://gitlab.com/gitlab-org/analytics-section/product-analytics/gl-application-sdk-rb

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport-gitlab>=5.2:devel/rubygem-activesupport-gitlab \
		rubygem-rake>=13.0<14:devel/rubygem-rake \
		rubygem-snowplow-tracker>=0.8.0<0.9:devel/rubygem-snowplow-tracker

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
