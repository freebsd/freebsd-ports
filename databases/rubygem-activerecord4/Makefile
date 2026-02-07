PORTNAME=	activerecord
PORTVERSION=	4.2.11.3
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails/tree/main/activerecord

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel4>=${PORTVERSION}:databases/rubygem-activemodel4 \
		rubygem-activesupport4>=${PORTVERSION}:devel/rubygem-activesupport4 \
		rubygem-arel6>=6.0<7:databases/rubygem-arel6

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.2\.

.include <bsd.port.mk>
