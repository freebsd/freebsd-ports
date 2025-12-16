PORTNAME=	devise
PORTVERSION=	4.9.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Flexible authentication solution for Rails with Warden
WWW=		https://github.com/heartcombo/devise

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-bcrypt>=3.0<4:security/rubygem-bcrypt \
		rubygem-orm_adapter>=0.1<1:devel/rubygem-orm_adapter \
		rubygem-railties80>=4.1.0:www/rubygem-railties80 \
		rubygem-responders-rails80>=0:www/rubygem-responders-rails80 \
		rubygem-warden>=1.2.3<1.3:devel/rubygem-warden

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	plataformatec

.include <bsd.port.mk>
