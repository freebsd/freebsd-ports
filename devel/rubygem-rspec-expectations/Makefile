# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rspec-expectations
PORTVERSION=	3.5.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rspec-expectations adds should and should_not to every object

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-diff-lcs>=1.2.0:textproc/rubygem-diff-lcs \
		rubygem-rspec-support>=${PORTVERSION:R}:devel/rubygem-rspec-support

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
