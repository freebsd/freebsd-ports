PORTNAME=	simple_form
PORTVERSION=	5.0.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Forms made easy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel5>=5.0:databases/rubygem-activemodel5 \
		rubygem-actionpack5>=5.0:www/rubygem-actionpack5

USES=		cpe gem
CPE_VENDOR=	plataformatec
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
