# $FreeBSD$

PORTNAME=	gitlab_git
PORTVERSION=	7.2.19
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitLab wrapper around git objects

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport4>=4.0:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-charlock_holmes>=0.6:${PORTSDIR}/textproc/rubygem-charlock_holmes \
		rubygem-gitlab-linguist>=3.0:${PORTSDIR}/textproc/rubygem-gitlab-linguist \
		rubygem-rugged>=0.22.2:${PORTSDIR}/devel/rubygem-rugged

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
