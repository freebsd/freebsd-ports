PORTNAME=	jbuilder
PORTVERSION=	2.13.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create JSON structures via a Builder-style DSL
WWW=		https://github.com/rails/jbuilder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview61>=5.0.0:devel/rubygem-actionview61 \
		rubygem-activesupport61>=5.0.0:devel/rubygem-activesupport61

USES=		gem shebangfix

NO_ARCH=	yes

PORTCOUT=	limit:^2\.13\.

SHEBANG_FILES=	bin/test

.include <bsd.port.mk>
