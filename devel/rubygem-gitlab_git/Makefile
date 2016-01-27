# $FreeBSD$

PORTNAME=	gitlab_git
PORTVERSION=	7.2.24
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitLab wrapper around git objects

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport4>=4.0:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-charlock_holmes>=0.7.3:${PORTSDIR}/textproc/rubygem-charlock_holmes \
		rubygem-github-linguist>=4.7.0:${PORTSDIR}/textproc/rubygem-github-linguist \
		rubygem-rugged>=0.23.3:${PORTSDIR}/devel/rubygem-rugged

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
