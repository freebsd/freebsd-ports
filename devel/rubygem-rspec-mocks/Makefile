# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rspec-mocks
PORTVERSION=	3.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rspec-mocks provides a test-double framework for rspec

LICENSE=	MIT

RUN_DEPENDS=	rubygem-diff-lcs>=1.2.0:${PORTSDIR}/textproc/rubygem-diff-lcs \
		rubygem-rspec-support>=${PORTVERSION:R}:${PORTSDIR}/devel/rubygem-rspec-support

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
