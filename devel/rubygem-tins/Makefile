PORTNAME=	tins
PORTVERSION=	1.48.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Useful tools library in Ruby
WWW=		https://github.com/flori/tins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bigdecimal>=0:math/rubygem-bigdecimal \
		rubygem-mize>=0.6<1:devel/rubygem-mize \
		rubygem-sync>=0:devel/rubygem-sync

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
