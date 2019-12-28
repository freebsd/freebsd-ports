# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	dm-types
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DataMapper plugin providing extra data types

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bcrypt-ruby>=3.0<4:security/rubygem-bcrypt-ruby \
		rubygem-dm-core>=1.2.0<1.3:databases/rubygem-dm-core \
		rubygem-fastercsv>=1.5<2:devel/rubygem-fastercsv \
		rubygem-json1>=1.6<2:devel/rubygem-json1 \
		rubygem-multi_json>=1.0<2:devel/rubygem-multi_json \
		rubygem-stringex>=1.4:devel/rubygem-stringex \
		rubygem-uuidtools>=2.1<3:devel/rubygem-uuidtools

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
