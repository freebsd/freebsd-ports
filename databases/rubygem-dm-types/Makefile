# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	dm-types
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DataMapper plugin providing extra data types

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bcrypt-ruby>=3.0:security/rubygem-bcrypt-ruby \
		rubygem-dm-core>=1.2.0:databases/rubygem-dm-core \
		rubygem-fastercsv>=1.5:devel/rubygem-fastercsv \
		rubygem-json>=1.6:devel/rubygem-json \
		rubygem-multi_json>=1.0:devel/rubygem-multi_json \
		rubygem-stringex>=1.4:devel/rubygem-stringex \
		rubygem-uuidtools>=2.1:devel/rubygem-uuidtools

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
