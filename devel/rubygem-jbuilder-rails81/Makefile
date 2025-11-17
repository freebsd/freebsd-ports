PORTNAME=	jbuilder
PORTVERSION=	2.14.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails81

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create JSON structures via a Builder-style DSL
WWW=		https://github.com/rails/jbuilder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview81>=7.0.0:devel/rubygem-actionview81 \
		rubygem-activesupport81>=7.0.0:devel/rubygem-activesupport81

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	bin/test

.include <bsd.port.mk>
