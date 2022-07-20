PORTNAME=	gitlab-dangerfiles
PORTVERSION=	3.4.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Dangerfile and plugins for GitLab projects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-danger>=8.4.5:devel/rubygem-danger \
		rubygem-danger-gitlab>=8.0.0:devel/rubygem-danger-gitlab \
		rubygem-rake>=0:devel/rubygem-rake

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
