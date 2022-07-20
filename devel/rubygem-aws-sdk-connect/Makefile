PORTNAME=	aws-sdk-connect
PORTVERSION=	1.74.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official AWS Ruby gem for Amazon Connect Service (Amazon Connect)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-sdk-core>=3.127.0<4:devel/rubygem-aws-sdk-core \
		rubygem-aws-sigv4>=1.1<2:devel/rubygem-aws-sigv4

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
