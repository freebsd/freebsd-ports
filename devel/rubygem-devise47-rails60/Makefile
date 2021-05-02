# Created by: rpsfa@rit.edu

PORTNAME=	devise
PORTVERSION=	4.7.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	47-rails60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Flexible authentication solution for Rails with Warden

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-bcrypt>=3.0<4:security/rubygem-bcrypt \
		rubygem-orm_adapter>=0.1<1:devel/rubygem-orm_adapter \
		rubygem-railties60>=4.1.0:www/rubygem-railties60 \
		rubygem-responders-rails60>=0:www/rubygem-responders-rails60 \
		rubygem-warden>=1.2.3<1.3:devel/rubygem-warden

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.7\.

.include <bsd.port.mk>
