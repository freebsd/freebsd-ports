PORTNAME=	simple_form
DISTVERSION=	5.3.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Forms made easy
WWW=		https://github.com/heartcombo/simple_form

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

DEPRECATED=	Ruby on Rails 6.1.x reaches EOL on 2024-10-01
EXPIRATION_DATE=	2024-10-24

RUN_DEPENDS=	rubygem-actionpack61>=5.2:www/rubygem-actionpack61 \
		rubygem-activemodel61>=5.2:databases/rubygem-activemodel61

USES=		cpe gem
CPE_VENDOR=	plataformatec

NO_ARCH=	yes

.include <bsd.port.mk>
