# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	dm-active_model
PORTVERSION=	1.2.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DM plugin for active_model compliance and thus rails 3 compatibility

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel>=3.0:databases/rubygem-activemodel \
		rubygem-dm-core>=1.2.0:databases/rubygem-dm-core

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

DEPRECATED=	Depends on deprecated databases/rubygem-activemodel
EXPIRATION_DATE=	2017-01-07

.include <bsd.port.mk>
