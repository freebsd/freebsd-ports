# $FreeBSD$

PORTNAME=	launchy
PORTVERSION=	2.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	22

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Helper class for launching cross-platform applications

RUN_DEPENDS=	rubygem-addressable>=2.3:${PORTSDIR}/www/rubygem-addressable

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

# Don't install the binary bin/launchy since it's not required at this time

PORTSCOUT=	limit:^2\.2

.include <bsd.port.mk>
