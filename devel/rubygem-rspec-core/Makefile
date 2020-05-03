# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rspec-core
PORTVERSION=	3.9.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RSpec Core provides the structure for writing executable examples

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-rspec-support>=${PORTVERSION:R}.3<3.10:devel/rubygem-rspec-support

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rspec

.include <bsd.port.mk>
