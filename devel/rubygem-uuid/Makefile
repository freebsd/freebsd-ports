# New ports collection makefile for:	rubygem-uuid
# Date created:		06 Nov 2008
# Whom:			Wen Heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uuid
PORTVERSION=	2.0.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RF/reliable-msg

MAINTAINER=	wenheping@gmail.com
COMMENT=	UUID Generator for Ruby

BUILD_DEPENDS=	rubygem-macaddr>=1.0.0:${PORTSDIR}/net/rubygem-macaddr
RUN_DEPENDS=	rubygem-macaddr>=1.0.0:${PORTSDIR}/net/rubygem-macaddr

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
