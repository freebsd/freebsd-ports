# Created by: Mikhail T. <m.tsatsenko@gmail.com>
# $FreeBSD$

PORTNAME=	rubytree
PORTVERSION=	1.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Implementation of the Tree data structure for the Ruby

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-json>=2.1<3:devel/rubygem-json \
		rubygem-structured_warnings>=0.3<1:devel/rubygem-structured_warnings

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
