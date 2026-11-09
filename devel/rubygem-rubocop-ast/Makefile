PORTNAME=	rubocop-ast
PORTVERSION=	1.50.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RuboCop Node and NodePattern classes
WWW=		https://docs.rubocop.org/rubocop-ast/ \
		https://github.com/rubocop/rubocop-ast

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-parser>=3.3.7.2:devel/rubygem-parser \
		rubygem-prism1>=1.7<2:textproc/rubygem-prism1

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
