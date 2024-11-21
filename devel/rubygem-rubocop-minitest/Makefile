PORTNAME=	rubocop-minitest
PORTVERSION=	0.36.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatic Minitest code style checking tool
WWW=		https://docs.rubocop.org/rubocop-minitest/ \
		https://github.com/rubocop/rubocop-minitest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-rubocop>=1.61<2.0:devel/rubygem-rubocop \
		rubygem-rubocop-ast>=1.31.1<2.0:devel/rubygem-rubocop-ast

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
