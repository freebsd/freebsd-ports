# New ports collection makefile for: rubygem-data_objects
# Date created:		18 April 2009
# Whom:		Espen Volden aka voldern <voldern@hoeggen.net>
#
# $FreeBSD$
#

PORTNAME=	data_objects
PORTVERSION=	0.9.11
CATEGORIES=	databases rubygems
MASTER_SITES=	RUBYFORGE/dorb
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	voldern@hoeggen.net
COMMENT=	A unified Ruby API for popular databases

BUILD_DEPENDS=	rubygem-addressable>=2.0:${PORTSDIR}/www/rubygem-addressable \
		rubygem-extlib>=0.9.9:${PORTSDIR}/devel/rubygem-extlib

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
