PORTNAME=	gitlab-dangerfiles
PORTVERSION=	4.10.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Dangerfile and plugins for GitLab projects
WWW=		https://gitlab.com/gitlab-org/ruby/gems/gitlab-dangerfiles

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-danger>=9.3.0:devel/rubygem-danger \
		rubygem-danger-gitlab>=8.0.0:devel/rubygem-danger-gitlab \
		rubygem-rake>=13<14:devel/rubygem-rake

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
