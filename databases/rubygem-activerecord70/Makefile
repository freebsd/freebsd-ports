PORTNAME=	activerecord
PORTVERSION=	7.0.6
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework
WWW=		https://github.com/rails/rails/tree/main/activerecord \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel70>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activemodel70 \
		rubygem-activesupport70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport70

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
