# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	4.1.6
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel4>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activemodel4 \
		rubygem-activesupport4>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-arel>=5.0.0:${PORTSDIR}/databases/rubygem-arel

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
