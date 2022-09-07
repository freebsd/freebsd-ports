PORTNAME=	activerecord
PORTVERSION=	6.1.6.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework
WWW=		https://github.com/rails/rails/tree/main/activerecord

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel61>=${PORTVERSION}:databases/rubygem-activemodel61 \
		rubygem-activesupport61>=${PORTVERSION}:devel/rubygem-activesupport61

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
