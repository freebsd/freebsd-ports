# New ports collection makefile for:	rubygem-dm-active_model
# Date created:		2011-06-16
# Whom:			Ryan Steinmetz <rpsfa@rit.edu>
#
# $FreeBSD$
#

PORTNAME=	dm-active_model
PORTVERSION=	1.1.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A dm plugin for active_model compliance and thus rails 3 compatibility

RUN_DEPENDS=	rubygem-activemodel>=3.0.4:${PORTSDIR}/databases/rubygem-activemodel \
		rubygem-dm-core>=1.1.0:${PORTSDIR}/databases/rubygem-dm-core

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
