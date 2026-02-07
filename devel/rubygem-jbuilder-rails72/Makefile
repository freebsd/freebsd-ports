PORTNAME=	jbuilder
PORTVERSION=	2.14.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create JSON structures via a Builder-style DSL
WWW=		https://github.com/rails/jbuilder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview72>=7.0.0:devel/rubygem-actionview72 \
		rubygem-activesupport72>=7.0.0:devel/rubygem-activesupport72

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	bin/test

.include <bsd.port.mk>
