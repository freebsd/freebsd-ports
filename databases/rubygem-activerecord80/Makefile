PORTNAME=	activerecord
PORTVERSION=	8.0.2.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework
WWW=		https://github.com/rails/rails/tree/main/activerecord \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel80>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activemodel80 \
		rubygem-activesupport80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport80 \
		rubygem-timeout>=0.4.0:devel/rubygem-timeout

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.0\.

.include <bsd.port.mk>
