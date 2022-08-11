PORTNAME=	simple_form
PORTVERSION=	4.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Forms made easy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel4>=4:databases/rubygem-activemodel4 \
		rubygem-actionpack4>=4:www/rubygem-actionpack4

PORTSCOUT=	ignore:1

USES=		cpe gem
CPE_VENDOR=	plataformatec
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
