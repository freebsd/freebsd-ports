# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rspec-expectations
PORTVERSION=	3.9.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rspec-expectations adds should and should_not to every object

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-diff-lcs>=1.2.0<2.0:textproc/rubygem-diff-lcs \
		rubygem-rspec-support>=${PORTVERSION:R}.0<3.10:devel/rubygem-rspec-support

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
