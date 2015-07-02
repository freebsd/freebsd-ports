# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbi
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Vendor independent interface for accessing databases

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-deprecated2>=2.0.1:${PORTSDIR}/devel/rubygem-deprecated2 \
		rubygem-aspectr>=0:${PORTSDIR}/devel/rubygem-aspectr

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/dbi bin/test_broken_dbi

.include <bsd.port.mk>
