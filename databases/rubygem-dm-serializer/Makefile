# New ports collection makefile for:	rubygem-dm-serializer
# Date created:		2010-08-26
# Whom:			Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	dm-serializer
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DataMapper plugin for serializing Resources and Collections

RUN_DEPENDS=	rubygem-dm-core>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-core \
  				rubygem-json_pure>=1.4:${PORTSDIR}/devel/rubygem-json_pure \
				rubygem-fastercsv>=1.5.3:${PORTSDIR}/devel/rubygem-fastercsv

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
