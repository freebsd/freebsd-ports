# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	authlogic
PORTVERSION=	3.8.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Clean, simple, and unobtrusive Ruby authentication solution

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord4>=3.2:databases/rubygem-activerecord4 \
		rubygem-activesupport4>=3.2:devel/rubygem-activesupport4 \
		rubygem-request_store>=1.0:devel/rubygem-request_store \
		rubygem-scrypt>=1.2:security/rubygem-scrypt

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
