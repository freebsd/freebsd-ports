PORTNAME=	rubygems-tasks
PORTVERSION=	0.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rake tasks for managing and releasing Ruby Gems
WWW=		https://github.com/postmodern/rubygems-tasks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-irb>=1.0<2:devel/rubygem-irb \
		rubygem-rake>=10.0.0:devel/rubygem-rake

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
