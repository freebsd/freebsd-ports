PORTNAME=	state_machines-activerecord
PORTVERSION=	0.8.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Support for creating state machines for attributes on ActiveRecord
WWW=		https://github.com/state-machines/state_machines-activerecord

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activerecord-gitlab>=5.1:databases/rubygem-activerecord-gitlab \
		rubygem-state_machines-activemodel-gitlab>=0.8.0:databases/rubygem-state_machines-activemodel-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
