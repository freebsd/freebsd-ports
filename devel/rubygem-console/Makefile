PORTNAME=	console
PORTVERSION=	1.33.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Beautiful logging for Ruby
WWW=		https://socketry.github.io/console/ \
		https://github.com/socketry/console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-fiber-annotation>=0:devel/rubygem-fiber-annotation \
		rubygem-fiber-local>=1.1<2:devel/rubygem-fiber-local \
		rubygem-json>=0:devel/rubygem-json

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
