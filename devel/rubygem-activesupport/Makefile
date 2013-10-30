# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	activesupport
PORTVERSION=	3.2.15
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Utility classes and extension that are required by Rails MVC Framework

RUN_DEPENDS=	rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-i18n>=0.6.4:${PORTSDIR}/devel/rubygem-i18n

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

USE_RUBY_FEATURES=	iconv

NOPORTDOCS=	yes

.include <bsd.port.mk>
