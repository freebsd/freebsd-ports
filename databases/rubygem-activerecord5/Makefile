PORTNAME=	activerecord
PORTVERSION=	5.1.7
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel5>=${PORTVERSION}:databases/rubygem-activemodel5 \
		rubygem-activesupport5>=${PORTVERSION}:devel/rubygem-activesupport5 \
		rubygem-arel8>=8.0,1<9,1:databases/rubygem-arel8

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^5\.1\.

.include <bsd.port.mk>
