PORTNAME=	simple_form
PORTVERSION=	5.0.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Forms made easy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel50>=5.0:databases/rubygem-activemodel50 \
		rubygem-actionpack50>=5.0:www/rubygem-actionpack50

USES=		cpe gem
CPE_VENDOR=	plataformatec
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
