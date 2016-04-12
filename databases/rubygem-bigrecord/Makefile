# Created by: Philip M. Gollucci
# $FreeBSD$

PORTNAME=	bigrecord
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Intended to work as a drop-in for Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord4>=0:databases/rubygem-activerecord4 \
		rubygem-activesupport4>=0:devel/rubygem-activesupport4 \
		rubygem-uuidtools>=2.0.0:devel/rubygem-uuidtools

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
