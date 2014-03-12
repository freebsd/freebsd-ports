# $FreeBSD$

PORTNAME=	librarian
PORTVERSION=	0.1.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@robakdesign.com
COMMENT=	Ruby framework for writing bundlers

LICENSE=	MIT

RUN_DEPENDS=	${PKGNAMEPREFIX}highline>=0:${PORTSDIR}/devel/rubygem-highline \
		${PKGNAMEPREFIX}thor>=0.15:${PORTSDIR}/devel/rubygem-thor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
