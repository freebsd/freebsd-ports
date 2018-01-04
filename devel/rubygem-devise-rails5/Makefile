# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	devise
PORTVERSION=	4.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Flexible authentication solution for Rails with Warden

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-bcrypt>=3.0:security/rubygem-bcrypt \
		rubygem-orm_adapter>=0.1:devel/rubygem-orm_adapter \
		rubygem-railties5>=4.1.0:www/rubygem-railties5 \
		rubygem-responders-rails5>=0:www/rubygem-responders-rails5 \
		rubygem-warden>=1.2.3:devel/rubygem-warden

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

post-patch:
	@${REINPLACE_CMD} -e 's|, "test/rails_app/config/routes.rb"||' ${WRKSRC}/${PORTNAME}.gemspec

.include <bsd.port.mk>
