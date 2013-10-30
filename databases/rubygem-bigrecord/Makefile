# Created by: Philip M. Gollucci
# $FreeBSD$

PORTNAME=	bigrecord
PORTVERSION=	0.1.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Intended to work as a drop-in for Rails applications

RUN_DEPENDS=	rubygem-activerecord>=0:${PORTSDIR}/databases/rubygem-activerecord \
			    rubygem-activesupport>=0:${PORTSDIR}/devel/rubygem-activesupport \
				rubygem-uuidtools>=2.0.0:${PORTSDIR}/devel/rubygem-uuidtools

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
