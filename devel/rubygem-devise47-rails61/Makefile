PORTNAME=	devise
PORTVERSION=	4.7.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	47-rails61

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Flexible authentication solution for Rails with Warden

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-bcrypt>=3.0<4:security/rubygem-bcrypt \
		rubygem-orm_adapter>=0.1<1:devel/rubygem-orm_adapter \
		rubygem-railties61>=4.1.0:www/rubygem-railties61 \
		rubygem-responders-rails61>=0:www/rubygem-responders-rails61 \
		rubygem-warden>=1.2.3<1.3:devel/rubygem-warden

USES=		cpe gem
USE_RUBY=	yes

CPE_VENDOR=	plataformatec

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.7\.

.include <bsd.port.mk>
