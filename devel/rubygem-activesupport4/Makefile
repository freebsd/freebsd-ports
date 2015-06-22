# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	activesupport
PORTVERSION=	4.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Utility classes and extension that are required by Rails MVC Framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-i18n>=0.6.9:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-json>=1.7.7:${PORTSDIR}/devel/rubygem-json \
		rubygem-minitest>=5.1:${PORTSDIR}/devel/rubygem-minitest \
		rubygem-thread_safe>=0.3:${PORTSDIR}/devel/rubygem-thread_safe \
		rubygem-tzinfo>=1.1:${PORTSDIR}/devel/rubygem-tzinfo

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
