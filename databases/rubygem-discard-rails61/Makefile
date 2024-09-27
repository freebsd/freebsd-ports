PORTNAME=	discard
PORTVERSION=	1.3.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Allows marking ActiveRecord objects as discarded
WWW=		https://github.com/jhawthorn/discard

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Ruby on Rails 6.1.x reaches EOL on 2024-10-01
EXPIRATION_DATE=	2024-10-24

RUN_DEPENDS=	rubygem-activerecord61>=4.2<8:databases/rubygem-activerecord61

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
