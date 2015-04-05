# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rspec-core
PORTVERSION=	3.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RSpec Core provides the structure for writing executable examples

LICENSE=	MIT

RUN_DEPENDS=	rubygem-rspec-support>=${PORTVERSION:R}:${PORTSDIR}/devel/rubygem-rspec-support

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rspec

.include <bsd.port.mk>
