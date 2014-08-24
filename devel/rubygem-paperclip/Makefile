# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	paperclip
PORTVERSION=	4.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy upload management for ActiveRecord

RUN_DEPENDS=	rubygem-activemodel>=3.0.0:${PORTSDIR}/databases/rubygem-activemodel \
		rubygem-activesupport>=3.0.0:${PORTSDIR}/devel/rubygem-activesupport \
    		rubygem-cocaine>=0.5.3:${PORTSDIR}/devel/rubygem-cocaine \
    		rubygem-mime-types>=0:${PORTSDIR}/misc/rubygem-mime-types

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
