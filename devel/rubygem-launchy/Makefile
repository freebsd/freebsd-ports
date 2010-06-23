# Ports collection makefile for:	gem-launchy
# Date created:				06 Nov 2009
# Whom:					Ryan Steinmetz (<rpsfa@rit.edu>)
#
# $FreeBSD$

PORTNAME=	launchy
PORTVERSION=	0.3.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	rpsfa@rit.edu
COMMENT=	A helper class for launching cross-platform applications

RUN_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
		rubygem-configuration>=1.1.0:${PORTSDIR}/devel/rubygem-configuration

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES+=	bin/launchy

.include <bsd.port.mk>
