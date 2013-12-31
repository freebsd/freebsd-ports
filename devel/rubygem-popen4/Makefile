# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	popen4
PORTVERSION=	0.1.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	${GEM_NAME}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Cross platform API for managing child processes

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-open4>=0.4.0:${PORTSDIR}/devel/rubygem-open4 \
		rubygem-platform>=0.4.0:${PORTSDIR}/devel/rubygem-platform

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
GEM_NAME=	POpen4-${PORTVERSION}

.include <bsd.port.mk>
