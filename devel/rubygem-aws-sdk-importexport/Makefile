# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	aws-sdk-importexport
PORTVERSION=	1.35.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official AWS Ruby gem for AWS Import/Export

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-sdk-core>=3.127.0<4:devel/rubygem-aws-sdk-core \
		rubygem-aws-sigv2>=1.0<2:devel/rubygem-aws-sigv2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
