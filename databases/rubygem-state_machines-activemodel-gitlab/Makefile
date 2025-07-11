PORTNAME=	state_machines-activemodel
PORTVERSION=	0.31.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Support for creating state machines for attributes on ActiveModel
WWW=		https://github.com/state-machines/state_machines-activemodel

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activemodel-gitlab>=7.1:databases/rubygem-activemodel-gitlab \
		rubygem-state_machines>=0.31.0:devel/rubygem-state_machines

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
