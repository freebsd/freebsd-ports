# New ports collection makefile for:	rubygem-uuid
# Date created:		06 Nov 2008
# Whom:			Wen Heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uuid
PORTVERSION=	2.3.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	wen@FreeBSD.org
COMMENT=	UUID Generator for Ruby

RUN_DEPENDS=	rubygem-macaddr>=1.0.0:${PORTSDIR}/net/rubygem-macaddr

PLIST_FILES+=	bin/uuid

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
