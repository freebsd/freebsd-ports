PORTNAME=	activerecord
PORTVERSION=	7.0.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel70>=${PORTVERSION}:databases/rubygem-activemodel70 \
		rubygem-activesupport70>=${PORTVERSION}:devel/rubygem-activesupport70

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
