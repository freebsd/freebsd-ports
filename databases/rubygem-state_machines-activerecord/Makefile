PORTNAME=	state_machines-activerecord
PORTVERSION=	0.8.0
PORTREVISION=	0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Support for creating state machines for attributes on ActiveRecord

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activerecord60>=5.1:databases/rubygem-activerecord60 \
		rubygem-state_machines-activemodel>=0.8.0:databases/rubygem-state_machines-activemodel

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
