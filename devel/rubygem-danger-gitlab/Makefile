PORTNAME=	danger-gitlab
PORTVERSION=	8.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Code Review

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-danger>=0:devel/rubygem-danger \
		rubygem-gitlab>=0.9.2:devel/rubygem-gitlab

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
