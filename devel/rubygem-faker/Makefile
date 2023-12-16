PORTNAME=	faker
PORTVERSION=	3.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for generating fake data: names, addresses, phone numbers
WWW=		https://github.com/faker-ruby/faker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

RUN_DEPENDS=	rubygem-i18n>=1.8.11,2<2,2:devel/rubygem-i18n

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/faker

CONFLICTS_INSTALL=	py*-Faker

.include <bsd.port.mk>
