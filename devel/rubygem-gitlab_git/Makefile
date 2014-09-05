# $FreeBSD$

PORTNAME=	gitlab_git
PORTVERSION=	6.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitLab wrapper around git objects

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport4>=4.0:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-charlock_holmes>=0.6:${PORTSDIR}/textproc/rubygem-charlock_holmes \
		rubygem-github-linguist>=2.3.4:${PORTSDIR}/textproc/rubygem-github-linguist \
		rubygem-gitlab-grit>=2.6.0:${PORTSDIR}/textproc/rubygem-gitlab-grit \
		rubygem-rugged>=0:${PORTSDIR}/devel/rubygem-rugged

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
