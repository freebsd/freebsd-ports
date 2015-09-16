# $FreeBSD$

PORTNAME=	virtus
PORTVERSION=	1.0.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Attributes on Steroids for Plain Old Ruby Objects

LICENSE=	MIT

RUN_DEPENDS=	rubygem-axiom-types>=0.1:${PORTSDIR}/devel/rubygem-axiom-types \
		rubygem-coercible>=1.0:${PORTSDIR}/devel/rubygem-coercible \
		rubygem-descendants_tracker>=0.0.3:${PORTSDIR}/devel/rubygem-descendants_tracker \
		rubygem-equalizer>=0.0.9:${PORTSDIR}/devel/rubygem-equalizer

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
