PORTNAME=	rubocop-minitest
PORTVERSION=	0.37.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatic Minitest code style checking tool
WWW=		https://docs.rubocop.org/rubocop-minitest/ \
		https://github.com/rubocop/rubocop-minitest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-lint_roller>=1.1<2:devel/rubygem-lint_roller \
		rubygem-rubocop>=1.72.1<2.0:devel/rubygem-rubocop \
		rubygem-rubocop-ast>=1.38.0<2.0:devel/rubygem-rubocop-ast

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
