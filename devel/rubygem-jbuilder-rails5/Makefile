PORTNAME=	jbuilder
PORTVERSION=	2.13.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create JSON structures via a Builder-style DSL
WWW=		https://github.com/rails/jbuilder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview5>=5.0.0:devel/rubygem-actionview5 \
		rubygem-activesupport5>=5.0.0:devel/rubygem-activesupport5

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	bin/test

.include <bsd.port.mk>
