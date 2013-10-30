# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	paperclip
PORTVERSION=	3.4.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy upload management for ActiveRecord

RUN_DEPENDS=	rubygem-activemodel>=3.0.0:${PORTSDIR}/databases/rubygem-activemodel \
    		rubygem-activerecord>=3.0.0:${PORTSDIR}/databases/rubygem-activerecord \
		rubygem-activesupport>=3.0.0:${PORTSDIR}/devel/rubygem-activesupport \
    		rubygem-cocaine>=0.5.0:${PORTSDIR}/devel/rubygem-cocaine \
    		rubygem-mime-types>=0:${PORTSDIR}/misc/rubygem-mime-types

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
