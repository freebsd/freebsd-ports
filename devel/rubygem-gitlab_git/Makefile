# $FreeBSD$

PORTNAME=	gitlab_git
PORTVERSION=	10.5.0
PORTEPOCH=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitLab wrapper around git objects

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport4>=4.0:devel/rubygem-activesupport4 \
		rubygem-charlock_holmes>=0.7.3:textproc/rubygem-charlock_holmes \
		rubygem-github-linguist>=4.7.0:textproc/rubygem-github-linguist \
		rubygem-rugged>=0.24.0:devel/rubygem-rugged

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
