# New ports collection makefile for:	rubygem-dm-serializer
# Date created:		2010-08-26
# Whom:			Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	dm-serializer
PORTVERSION=	1.2.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DataMapper plugin for serializing Resources and Collections

RUN_DEPENDS=	rubygem-dm-core>=1.2.0:${PORTSDIR}/databases/rubygem-dm-core \
  		rubygem-json>=1.5.4:${PORTSDIR}/devel/rubygem-json \
		rubygem-multi_json>=1.0.3:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-json_pure>=1.5.4:${PORTSDIR}/devel/rubygem-json_pure \
		rubygem-fastercsv>=1.5.4:${PORTSDIR}/devel/rubygem-fastercsv

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
