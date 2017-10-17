# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	activemodel
PORTVERSION=	4.2.10
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Toolkit for building modeling frameworks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=${PORTVERSION}:devel/rubygem-activesupport4 \
		rubygem-builder>=3.2.2:devel/rubygem-builder

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
